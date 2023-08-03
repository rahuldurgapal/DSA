#include<stdio.h>
void main()
{
    int i,j,mat1[3][3],mat2[3][3],mat3[3][3];
    printf("enter the elment of first matrix\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&mat1[i][j]);
        }

    }  
    printf("enter the element of second matrix\n");
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&mat2[i][j]);
        }

}
 for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }

    }
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\n",mat3[i][j]);
        }

}
}