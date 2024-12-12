# C / C++ 

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
