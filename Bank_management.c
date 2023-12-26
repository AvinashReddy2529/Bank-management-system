#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Define the Account structure
struct Account
{
    char name[50], gender[2];
    int age;
    long int account_number, tenure_fd;
    float deposit_amt, balance;
    long int mobile_num, aadhar_num;
};
// Define the Node structure for the linked list
struct Node
{
    struct Account account;
    struct Node *next;
};
void new_customer(struct Node **head);
void customer_login(struct Node *head);
void account_transaction(struct Node *node);
void account_withdrawal(struct Node *node);
void account_deposit(struct Node *node);
void account_loan(struct Node *node);
void account_homeloan(struct Node *node);
void account_vechileloan(struct Node *node);
void account_agricultureloan(struct Node *node);
void account_personalloan(struct Node *node);
void account_goldloan(struct Node *node);
void print_user_details(struct Node *head, long int account_number);
struct Node *search_account(struct Node *head, long int account_number);
int main()
{
    int choice_1;
    // Initialize the linked list head
    struct Node *head = NULL;
    system("CLS");
    while (1)
    {
        printf("\nBANK MANAGEMENT SYSTEM\n");
        printf("\nCustomer Services\n");
        printf("Enter\n");
        printf("1-For new user\n");
        printf("2-For existing user\n");
        printf("3-Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice_1);
        switch (choice_1)
        {
        case 1:
            new_customer(&head);
            break;
        case 2:
            customer_login(head);
            break;
        case 3:
            printf("Thank you! \nWe are happy to serve you.\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}
// Function to add a new customer to the linked list
void new_customer(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the name of the account holder: ");
    scanf("%s", newNode->account.name);
    printf("Enter age of account holder: ");
    scanf("%d", &newNode->account.age);
    if (newNode->account.age >= 18)
    {
        printf("Enter gender (M/F): ");
        scanf("%s", newNode->account.gender);
  if (strcmp(newNode->account.gender, "M") == 0 || strcmp(newNode->account.gender, "F") == 0)
        {
            printf("Enter mobile number for holder: ");
            scanf("%ld", &newNode->account.mobile_num);
            printf("Enter aadhar number of the holder: ");
            scanf("%ld", &newNode->account.aadhar_num);
            printf("Enter amount deposited in the account :");
            scanf("%f", &newNode->account.deposit_amt);
            newNode->account.balance = newNode->account.deposit_amt;
            printf("Enter the account number: ");
            scanf("%ld", &newNode->account.account_number);
            newNode->next = *head;
            *head = newNode;
            printf("Account successfully created.\n");
        }
        else
        {
            printf("Invalid gender. Eligibility criteria not met.\n");
            free(newNode);
        }
    }
    else
    {
        printf("User is not eligible. Age must be 18 or above.\n");
        free(newNode);
    }
}
// Function to search for an account based on account number
struct Node *search_account(struct Node *head, long int account_number)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->account.account_number == account_number)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
// Function to handle customer login
void customer_login(struct Node *head)
{
    long int account_number;
    int choice_3;
    printf("Enter the account Number: ");
    scanf("%ld", &account_number);
    struct Node *foundAccount = search_account(head, account_number);
    print_user_details(head, account_number);
    if (foundAccount != NULL)
    {
        printf("\nChoose an option:\n");
        printf("1- Transaction\n");
        printf("2- Apply for a loan\n");
        printf("Enter your choice : ");
        scanf("%d", &choice_3);
        switch (choice_3)
        {
        case 1:
            account_transaction(foundAccount);
            break;
        case 2:
            account_loan(foundAccount);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    else
    {
        printf("Account not found.\n");
    }
}
// Function to print user details based on account number
void print_user_details(struct Node *head, long int account_number)
{
    struct Node *foundAccount = search_account(head, account_number);
    if (foundAccount != NULL)
    {
        printf("\nThe Details of the Account Holder with Account Number %ld\n", account_number);
        printf("Name: %s\n", foundAccount->account.name);
        printf("Age: %d\n", foundAccount->account.age);
        printf("Gender: %s\n", foundAccount->account.gender);
        printf("Mobile Number: %ld\n", foundAccount->account.mobile_num);
        printf("Aadhar Number: %ld\n", foundAccount->account.aadhar_num);
        printf("Balance Amount: %.2f\n", foundAccount->account.balance);
    }
    else
    {
        printf("Account not found.\n");
    }
}
void account_transaction(struct Node *node)
{
    int choice_4;
    printf("\nEnter the choice of transaction you need\n");
    printf("\n1-Withdrawal");
    printf("\n2-Deposit");
    printf("\nEnter your choice : ");
    scanf("%d", &choice_4);
    switch (choice_4)
    {
    case 1:
        account_withdrawal(node);
        break;
    case 2:
        account_deposit(node);
        break;
    default:
        printf("Invalid Input");
        break;
    }
}
void account_withdrawal(struct Node *node)
{
    float amount_1;
    printf("Enter amount to withdrawal: ");
    scanf("%f", &amount_1);
    if (amount_1 > node->account.balance)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        node->account.balance -= amount_1;
        printf("Balance amount after the transaction is %.2f\n", node->account.balance);
    }
}
void account_deposit(struct Node *node)
{
    float amount_2;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount_2);
    node->account.balance += amount_2;
    printf("Balance amount after the transaction is %.2f\n", node->account.balance);
}
void account_loan(struct Node *node)
{
    int credit_score;
    int choice_5;
    printf("\nEnter your credit score: ");
    scanf("\n%d", &credit_score);
    if (credit_score < 70)
        printf("You're not eligible for a loan.\n");
    else if (credit_score >= 70)
    {
        printf("Select your choice of loan needed\n");
        printf("\n1-Home loan\n2-Vehicle loan\n3-Gold loan\n4-Agriculture loan\n5-Personal loan\n");
    }
    printf("Enter your choice : ");
    scanf("%d", &choice_5);
    switch (choice_5)
    {
    case 1:
        account_homeloan(node);
        break;
    case 2:
        account_vechileloan(node);
        break;
    case 3:
        account_goldloan(node);
        break;
    case 4:
        account_agricultureloan(node);
        break;
    case 5:
        account_personalloan(node);
        break;
    default:
        printf("");
        break;
    }
}
void account_homeloan(struct Node *node)
{
    int tenure;
    float loan_amt1, intrest, loan_amt2;
    printf("Enter the loan amount needed: ");
    scanf("\n%f", &loan_amt1);
    printf("Enter the tenure you would pay it back to the bank: ");
    scanf("\n%d", &tenure);
    printf("Your interest rate will be 6.80 per year\n");
    intrest = (loan_amt1 * 6.80 * tenure) / 100;
    loan_amt2 = loan_amt1 + intrest;
    printf("You have to pay %.2f amount by the end\n", loan_amt2);
    printf("Your monthly EMI will be %.2f\n", (loan_amt2 / (tenure * 12)));
}
void account_vechileloan(struct Node *node)
{
    int tenure;
    float loan_amt = 0;
    printf("Enter the loan amount needed: ");
    scanf("\n%f", &loan_amt);
    printf("Enter the tenure you would pay it back to the bank: ");
    scanf("\n%d", &tenure);
    printf("Your interest rate will be 7.65 per year\n");
    loan_amt += (loan_amt * 7.65 * tenure) / 100;
    printf("You have to pay %.2f amount by the end\n", loan_amt);
    printf("Your monthly EMI will be %.2f\n", (loan_amt / (tenure * 12)));
}
void account_agricultureloan(struct Node *node)
{
    float loan_amt = 0, acres;
    printf("Enter the number of acres you have: ");
    scanf("\n%f", &acres);
    loan_amt = acres * 50000;
    printf("You will get %.2f amount for this loan\n", loan_amt);
    printf("Your interest rate will be 3.50 per year\n");
    loan_amt += (loan_amt * 3.5) / 100;
    printf("You have to pay %.2f amount after selling the product\n", loan_amt);
}
void account_personalloan(struct Node *node)
{
    int tenure;
    float loan_amt = 0;
    printf("Enter the loan amount needed: ");
    scanf("\n%f", &loan_amt);
    printf("Enter the tenure you would pay it back to the bank: ");
    scanf("\n%d", &tenure);
    printf("Your interest rate will be 12.90 per year\n");
    loan_amt += (loan_amt * 12.90 * tenure) / 100;
    printf("You have to pay %.2f amount by the end\n", loan_amt);
    printf("Your monthly EMI will be %.2f\n", (loan_amt / (tenure * 12)));
}
void account_goldloan(struct Node *node)
{
    float wg_gold, loan_amt = 0;
    printf("Enter the weight of the gold (in gms) you are keeping as collateral: ");
    scanf("%f", &wg_gold);
    loan_amt = (wg_gold / 10) * 35000;
    printf("You will get %.2f loan amount\n", loan_amt);
    loan_amt += (loan_amt * 9.20) / 100;
    printf("You have to pay back %.2f amount by 1 year\n", loan_amt);
}