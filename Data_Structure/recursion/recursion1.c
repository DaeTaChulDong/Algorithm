//재귀로 factorial 계산
int factorial(int n){
    if(n<=1)
        return 1;
    else
    return n*factorial(n-1);
}

//반복으로 factorial 계산
int factorial_iter(int n){
    int i,result=1;
    
    for(i=1;i<=n;i++){
        result*=i;
        return result;
    }
}

//시간복잡도는 둘 다 O(n)으로 동일하나, 함수호출 오버헤드와 스택 공간이 필요하다는 점 때문에 재귀가 약간 더 느리다.
