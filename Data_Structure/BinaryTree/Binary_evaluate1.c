//트리의 응용: 수식트리를 통한 수식 계산(후위순회 응용)
//피연산자->단말노드, 연산자->비단말노드
//자식노드(피연산자)들에 대해 부모노드의 연산자를 적용한다. => 후위순회 알고리즘의 응용
function evaluate(exp) do //루트(연산자)
    if(exp==NULL) do
        return 0;
    end
    else do
        x <- evaluate(exp.left) //왼쪽 서브트리 계산 결과
        y <- evaluate(exp.right) //오른쪽 서브트리 계산 결과
        op <- exp.data
        return (x op y) //왼쪽, 오른쪽을 가져와서 부모 노드인 연산자로 계산
    end
end
//왼쪽 자식 계산->오른쪽 자식 계산->부모 노드로 계산