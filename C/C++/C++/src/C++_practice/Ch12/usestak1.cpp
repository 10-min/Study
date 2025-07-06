#include <iostream>
#include "stack1.h"

int main()
{
    Stack s1(5); // 크기 5인 스택 생성
    std::cout << "스택이 비었나? " << (s1.isempty() ? "예" : "아니오") << std::endl;

    // push 테스트
    for (int i = 1; i <= 5; ++i)
    {
        if (s1.push(i))
            std::cout << i << " push 성공\n";
        else
            std::cout << i << " push 실패\n";
    }

    std::cout << "스택이 가득 찼나? " << (s1.isfull() ? "예" : "아니오") << std::endl;

    // 복사 생성자 테스트
    Stack s2 = s1;
    std::cout << "복사 생성자 사용 후 pop:\n";
    Item item;
    while (s2.pop(item))
    {
        std::cout << item << " ";
    }
    std::cout << "\n";

    // 대입 연산자 테스트
    Stack s3(3);
    s3 = s1;
    std::cout << "대입 연산자 사용 후 pop:\n";
    while (s3.pop(item))
    {
        std::cout << item << " ";
    }
    std::cout << "\n";

    // 원래 스택 s1은 아직 유지되고 있는지 확인
    std::cout << "원래 스택 s1 pop:\n";
    while (s1.pop(item))
    {
        std::cout << item << " ";
    }
    std::cout << "\n";

    return 0;
}
