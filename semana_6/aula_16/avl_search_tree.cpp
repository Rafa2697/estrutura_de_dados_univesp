#include "avl_search_tree.h"

bool AVLSearchTree::isEmpty() const
{
  return root == NULL;
}

bool AVLSearchTree::isFull() const
{
  NodeType *location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (std::bad_alloc exception)
  {
    return true;
  }
}

void AVLSearchTree::destroyTree(NodeType *&tree)
{
  if (tree != NULL)
  {
    destroyTree(tree->filhoEsquerdo);
    destroyTree(tree->filhoDireito);
    delete tree;
  }
}

void AVLSearchTree::retrieveAluno(NodeType *tree,
                                  Aluno &aluno,
                                  bool &found) const
{
  if (tree == NULL)
    found = false;
  else if (aluno.getRa() < tree->aluno.getRa())
    retrieveAluno(tree->filhoEsquerdo, aluno, found);
  else if (aluno.getRa() > tree->aluno.getRa())
    retrieveAluno(tree->filhoDireito, aluno, found);
  else
  {
    aluno = tree->aluno;
    found = true;
  }
}

void AVLSearchTree::insertAluno(NodeType *&tree,
                                Aluno aluno,
                                bool &isTaller)
{
  if (tree == NULL)
  {
    tree = new NodeType;
    tree->filhoDireito = NULL;
    tree->filhoEsquerdo = NULL;
    tree->aluno = aluno;
    tree->fatorB = 0; // Acabamos de inserir uma folha
    isTaller = true;
    return;
  }
  if (aluno.getRa() < tree->aluno.getRa())
  {
    insertAluno(tree->filhoEsquerdo, aluno, isTaller);
    if (isTaller)
      tree->fatorB = tree->fatorB - 1;
  }
  else
  {
    insertAluno(tree->filhoDireito, aluno, isTaller);
    if (isTaller)
      tree->fatorB = tree->fatorB + 1;
  }
  // O performRotations vai ajustar o fatorB
  performRotations(tree);

  // Após a rotação, a árvore não muda de tamanho
  if (isTaller && tree->fatorB == 0)
  {
    isTaller = false;
  }
}

void AVLSearchTree::deleteAluno(NodeType *&tree, int aluno,
                                bool &isShorter)
{
  if (aluno < tree->aluno.getRa())
  {
    deleteAluno(tree->filhoEsquerdo, aluno, isShorter);
    if (isShorter)
      tree->fatorB = tree->fatorB + 1;
  }
  else if (aluno > tree->aluno.getRa())
  {
    deleteAluno(tree->filhoDireito, aluno, isShorter);
    if (isShorter)
      tree->fatorB = tree->fatorB - 1;
  }
  else if (aluno == tree->aluno.getRa())
  {
    deleteNode(tree, isShorter);
  }
  if (tree != NULL)
  {
    performRotations(tree);
    if (isShorter && tree->fatorB != 0)
    {
      isShorter = false;
    }
  }
}

void AVLSearchTree::deleteNode(NodeType *&tree, bool &isShorter)
{
  Aluno data;
  NodeType *tempPtr;
  tempPtr = tree;
  if (tree->filhoEsquerdo == NULL)
  {
    tree = tree->filhoDireito;
    isShorter = true;
    delete tempPtr;
  }
  else if (tree->filhoDireito == NULL)
  {
    tree = tree->filhoEsquerdo;
    isShorter = true;
    delete tempPtr;
  }
  else
  {
    getSuccessor(tree, data);
    tree->aluno = data;
    deleteAluno(tree->filhoDireito, data.getRa(), isShorter);
    if (isShorter)
      tree->fatorB = tree->fatorB - 1;
  }
}

void AVLSearchTree::getSuccessor(NodeType *tree, Aluno &data)
{
  tree = tree->filhoDireito;
  while (tree->filhoEsquerdo != NULL)
    tree = tree->filhoEsquerdo;
  data = tree->aluno;
}

void AVLSearchTree::printPreOrder(NodeType *tree) const
{
  if (tree != NULL)
  {
    std::cout << tree->aluno.getNome() << "[" << tree->fatorB << "] ";
    printPreOrder(tree->filhoEsquerdo);
    printPreOrder(tree->filhoDireito);
  }
}

void AVLSearchTree::printInOrder(NodeType *tree) const
{
  if (tree != NULL)
  {
    printInOrder(tree->filhoEsquerdo);
    std::cout << tree->aluno.getNome() << "[" << tree->fatorB << "] ";
    printInOrder(tree->filhoDireito);
  }
}

void AVLSearchTree::printPostOrder(NodeType *tree) const
{
  if (tree != NULL)
  {
    printPostOrder(tree->filhoEsquerdo);
    printPostOrder(tree->filhoDireito);
    std::cout << tree->aluno.getNome() << "[" << tree->fatorB << "] ";
  }
}

void AVLSearchTree::rotateToLeft(NodeType *&raizSubarvore) const
{
  NodeType *novaRaiz = raizSubarvore->filhoDireito;
  raizSubarvore->filhoDireito = novaRaiz->filhoEsquerdo;
  novaRaiz->filhoEsquerdo = raizSubarvore;
  raizSubarvore = novaRaiz;
}

void AVLSearchTree::rotateToRight(NodeType *&raizSubarvore) const
{
  NodeType *novaRaiz = raizSubarvore->filhoEsquerdo;
  raizSubarvore->filhoEsquerdo = novaRaiz->filhoDireito;
  novaRaiz->filhoDireito = raizSubarvore;
  raizSubarvore = novaRaiz;
}

void AVLSearchTree::rotateToLeftAndRight(NodeType *&raizSubarvore) const
{
  NodeType *filho = raizSubarvore->filhoEsquerdo;
  rotateToLeft(filho);
  raizSubarvore->filhoEsquerdo = filho;
  rotateToRight(raizSubarvore);
}

void AVLSearchTree::rotateToRightAndLeft(NodeType *&raizSubarvore) const
{
  NodeType *filho = raizSubarvore->filhoDireito;
  rotateToRight(filho);
  raizSubarvore->filhoDireito = filho;
  rotateToLeft(raizSubarvore);
}

void AVLSearchTree::performRotations(NodeType *&raizSubarvore) const
{
  NodeType *filho;
  NodeType *neto; // Usado em rotacao dupla

  // Rotacionar para a filhoDireito
  if (raizSubarvore->fatorB == -2)
  {
    filho = raizSubarvore->filhoEsquerdo;

    switch (filho->fatorB)
    {
    case -1: // Simples para a filhoDireito: Caso 1
      raizSubarvore->fatorB = 0;
      filho->fatorB = 0;
      rotateToRight(raizSubarvore);
      break;
    case 0: // Simples para a filhoDireito: Caso 2 -> Remoções
      raizSubarvore->fatorB = -1;
      filho->fatorB = +1;
      rotateToRight(raizSubarvore);
      break;
    case 1: // Rotacao dupla
      neto = filho->filhoDireito;

      switch (neto->fatorB)
      {
      case -1:
        raizSubarvore->fatorB = +1;
        filho->fatorB = 0;
        break;
      case 0:
        raizSubarvore->fatorB = 0;
        filho->fatorB = 0;
        break;
      case +1:
        raizSubarvore->fatorB = 0;
        filho->fatorB = -1;
        break;
      }
      neto->fatorB = 0;
      rotateToLeftAndRight(raizSubarvore);
    }
  }
  // Vamos rotacionar para a filhoEsquerdo
  else if (raizSubarvore->fatorB == +2)
  {
    filho = raizSubarvore->filhoDireito;

    switch (filho->fatorB)
    {
    case 1: // Simples para a filhoEsquerdo: Caso 1
      raizSubarvore->fatorB = 0;
      filho->fatorB = 0;
      rotateToLeft(raizSubarvore);
      break;
    case 0: // Simples para a filhoEsquerdo: Caso 2
      raizSubarvore->fatorB = +1;
      filho->fatorB = -1;
      rotateToLeft(raizSubarvore);
      break;
    case -1: // Rotacao dupla
      neto = filho->filhoEsquerdo;

      switch (neto->fatorB)
      {
      case -1:
        raizSubarvore->fatorB = 0;
        filho->fatorB = +1;
        break;
      case 0:
        raizSubarvore->fatorB = 0;
        filho->fatorB = 0;
        break;
      case +1:
        raizSubarvore->fatorB = -1;
        filho->fatorB = 0;
        break;
      }
      neto->fatorB = 0;
      rotateToRightAndLeft(raizSubarvore);
    }
  }
}
