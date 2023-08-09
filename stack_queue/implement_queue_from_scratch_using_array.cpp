void MyQueue ::push(int x)
{
    arr[rear++] = x;
}

int MyQueue ::pop()
{
    if (rear == front)
        return -1;
    return arr[front++];
}