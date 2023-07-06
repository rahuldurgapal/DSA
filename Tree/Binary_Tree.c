struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create()
{
    int x;
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node)\n");
    scanf("%d",&x);
    if(x==-1)
     return NULL;
    else{
     n->data=x;
     printf("Enter left child \n");
     node->left=create();

    }
    return n;
}



int main()
{
    struct node *root;
    root = NULL;
    root=create();
}