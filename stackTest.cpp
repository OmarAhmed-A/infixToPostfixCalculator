#include "intStack.h"
int main()
{
	Istack s;

	int choice = -1;

	while (choice != 4)
	{
		printf("1. Init Stack\n");
		printf("2. Push item\n");
		printf("3. Pop item\n");
		printf("4. Exit\n");

		printf("\n\nEnter a choice: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			int size;
			printf("Enter new size: ");
			scanf("%d", &size);
			//if(initializeStack(&s, size) == true)
			bool result = initializeStack(&s, size);
			if (result == true)
				printf("Stack initialized !\n");
			else
				printf("Stack cannot be initialized !\n");
		}
		else if (choice == 2)
		{
			int item;
			printf("Enter item: ");
			scanf("%d", &item);

			int result = push(&s, item);
			if (result == -1)
				printf("Please initialize stack first\n");
			else if (result == -2)
				printf("Stack overflow !\n");
			else
				printf("%d pushed into the stack !\n", item);
		}
		else if (choice == 3)
		{
			int item;
		
			int result = pop(&s, &item);
			if (result == -1)
				printf("Please initialize stack first\n");
			else if (result == -2)
				printf("Stack underflow !\n");
			else
				printf("%d popped from the stack !\n", item);
		}

	}
	
	return 0;
}