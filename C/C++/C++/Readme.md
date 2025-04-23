# C / C++ 

## iostream

### ios_base

- 부동소수점 소수점 자리수 고정 출력   
    `cout.setf(ios_base::fixed, ios_base::floatfield);`

- boolalpha 
``` cpp
std::cout.setf(ios_base::boolalpha);
// 출력 형태를 bool 형태로 변환
```

## string

### 문자변환
`int tolower(int ch)` : 소문자로 변환   

`int toupper(int ch)` : 대문자로 변환

``` cpp
include<strlib.h>

str = toLowerCase(str); // 소문자로
str = toUpperCase(str); // 대문자로
```

### 문자 확인
`int islower(int ch)` : 소문자인지 확인

`int isupper(int ch)` : 대문자인지 확인

## cmath

`M_PI` : 원주율

## stringstream

- str()
  - stringstream 내 string 반환
- str(string)
  - stringstream 내 string set
- 반복문 내 stringstream
  - [예제코드](https://github.com/AndroChung/Study/blob/175c4886172eca40d2eabce6f8162338f430b5b3/C%2C%20C%2B%2B/C%2B%2B/src/stringstream.cpp#L1C1-L29C14)

## vector

### erase
``` cpp
vector.erase(iterator);
```

### 개념

## argc 와 argv의 차이

- argc: "Argument Count"의 약자로, 명령줄 인수의 개수를 나타내는 정수(int)입니다.
- argv: "Argument Vector"의 약자로, 명령줄 인수를 저장하는 문자열 배열(포인터 배열, char *[])입니다.

## shared_ptr
> C++ 표준 라이브러리에서 제공하는 스마트 포인터(smart pointer) 중 하나로, 동적 할당된 메모리를 여러 객체가 안전하게 공유할 수 있게 해줍니다. 이는 메모리 관리의 복잡성을 줄이고, 메모리 누수나 dangling pointer(할당 해제된 메모리를 가리키는 포인터) 문제를 방지하는 데 유용합니다. ROS 2에서도 shared_ptr은 자주 사용되는데, 특히 노드나 객체를 효율적으로 관리할 때 많이 보입니다.
- 참조하면 참조 카운팅을함
- 해제는 자동
- 사용
  ``` cpp
  include <memory>
  std::shared_ptr
  ```

## placeholders
> 함수 호출 시 아직 정해지지 않은 인자 자리 표시자 주로 std::bind와 함게 사용
- 사용법
  ``` cpp
  std::placeholders::_1
  ```

## 기타

### using namespace std::chrono_literals
- 시간 관련 리터럴
- 500ms, 1s 등 사용 가능
