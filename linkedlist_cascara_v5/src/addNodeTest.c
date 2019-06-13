static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoProximo;
    Node* pNodoNuevo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(nodeIndex == 0)
        {
            pNodoAnterior = this->pFirstNode;
        }
        else
        {
            pNodoAnterior = getNode(this,nodeIndex - 1);
        }

        if(pNodoAnterior != NULL) pNodoProximo = pNodoAnterior;
        if(pNodoAnterior == NULL) pNodoProximo = NULL;

        pNodoNuevo = (Node*)malloc(sizeof(Node));
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            pNodoNuevo->pNextNode = pNodoProximo;

            if(nodeIndex == 0)
            {

                this->pFirstNode = pNodoNuevo;

            }
            else
                pNodoAnterior->pNextNode = pNodoNuevo;

            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}
