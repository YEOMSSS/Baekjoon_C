C언어를 시자아아아아아악 하겠습니다아아아

# Baekjoon

2025.08.12 Hello World!

# 궁금사항

scanf는 엔터로 구분된 입력도 그냥 일자로 받아버리네? 어떻게?  
python은 그런 거 못하잖아. 줄바꿈 해서 따로 입력받아야되는데.

# 괜찮게 푼 문제

3 Gold 5_2436 : 처음으로 풀어본 c언어 골드. while, if를 c에서는 이런 식으로 작성한다.
랜덤 마라톤 64_A 33964 : c언어에 대해 많은 것을 배웠다. 이 코드 하나로!

## 00. 기타

## 랜덤 마라톤 64

#### size_t

size_t는 "메모리의 크기나 길이를 나타낼 때 쓰는 자료형"이다.  
printf로 출력할 때는 %zu를 사용한다.

#### <string.h> strlen

문자열의 내용 길이를 반환한다. 배열이 얼마나 차 있는지를 반환한다고 생각하면 됨.  
널문자 \0이 나올 때까지 읽는다.  
`char arr[256] = "Hello";`
`printf("%zu\n", strlen(arr));   // 5  ('H','e','l','l','o');`

#### <stdio.h> sizeof

문자열 길이와 상관 없이 배열의 메모리 크기를 반환한다.  
`char arr[256];`
`printf("%zu\n", sizeof(arr));   // 256  (배열 전체 크기)`

#### && "" !

and &&, or ||, not !

#### abs()

파이썬과 동일하게 작동한다는거임. 절댓값 반환

#### 삼항 연산자 (조건 연산자)

조건식 ? 값1 : 값2  
조건식이 참(≠0)이면 → 값1 반환  
조건식이 거짓(=0)이면 → 값2 반환

#### static

static (함수 앞) → 이 파일 안에서만 쓸 수 있는 함수.  
여러 .c 파일을 묶어서 컴파일할 때, 함수 이름 충돌을 막아준다.

#### void

void → 함수가 값을 반환하지 않는다는 의미. 함수의 반환형(return type)이다.

#### int(input()) 을 c언어로 구현해보자

    #include <stdio.h>
    #include <stdlib.h>

    int main(void) {
        // 동적 메모리로 입력 버퍼 준비 (파이썬 input()처럼 가변적이라 가정)
        char *arr = malloc(100);  // 최대 99글자 + '\0' 입력 가능

        // 문자열 입력 (개행\0 포함됨)
        fgets(arr, 100, stdin);

        // 문자열 → 정수 변환 (에러 체크 생략)
        int x = atoi(arr);

        printf("%d\n", x);

        free(arr);  // malloc으로 확보했으니 해제
        return 0;
    }

#### <stdio.h> fgets

`char arr[256];`  
`fgets(arr, sizeof(arr), stdin);`  
말 그대로 input()의 느낌이다. 문자열+개행까지 입력받는다.  
최대 size-1 글자만 읽고 마지막에 \0 자동 추가.

#### stdin이 뭐냐고?

stdin : Standard Input (표준 입력, 보통 키보드)  
stdout : Standard Output (표준 출력, 보통 화면)  
stderr : Standard Error (에러 메시지 출력, 보통 화면)

#### <stdlib.h> malloc

`char *s = malloc(n + 1);` // 문자 n개 + '\0'
`s[n] = '\0'; ` // 직접 문자열의 끝을 표시해줘야 한다.

`int *arr = malloc(n * sizeof(int));` // n칸짜리 배열 만들기

`free(arr)` // 사용한 메모리를 꼭 반납해야 한다.

#### "큰따옴표", '작은따옴표'

"큰따옴표"는 char배열. 문자열이다. 끝에 \0이 붙는 문자열이다.  
'작은따옴표'는 그냥 char. 문자. 1바이트 정수다. 끝에 \0이 붙지 않는 한 글자다.

char c = 'a'; // 문자 하나 (ASCII 97)  
char s[] = "a"; // 문자 배열 {'a','\0'}

#### <stdlib.h> atoi(str);

이건 파이썬의 int(str)과 똑같은 역할을 한다.

#### <string.h> strcat(arr, "str");

strcat은 문자열을 이어붙이는 역할을 한다. arr의 가장 끝에 str을 붙여준다.  
배열의 크기를 초과하면 오류가 날 수 있다.

# 01. 단계별로 풀어보기

## 01. 입출력과 사칙연산 250817 ~

#### 배열 입력받기

    int nums[3], temp;
    for (int i = 0; i < 3; i++){
        scanf("%d", nums + i);
    }

&nums[i] 로 직접 주소를 입력할 수도 있다. nums + i 역시 같은 의미다.

#### int main, void main

int main(){ }로 돌릴 코드를 만들어준다.  
int랑 void는 우리가 사용할 땐 차이가 없다. 컴퓨터 방식의 차이일 뿐.  
웬만하면 int로 사용하는 것이 권장된다고 한다.

#### scanf("%d", &A)

input의 역할을 한다. 주소 값을 전달해야 하므로 &를 꼭 붙이자.

    %d : 10진수 정수 자료형
    %c : 문자 자료형 char
    %f : 부동소수 자료형 float
    %s : 문자열 자료형

#### 코드의 끝에는 ;를 붙인다

이게 없으면 c언어는 인식을 못하고 오류가 터져버린다.

#### return 0;

함수의 마지막에 써준다. 에러 없이 정상적으로 함수가 종료되었다는 것을 알리기 위함이다.  
솔직히 파이썬에서도 return안해도 함수 끝나는데 그냥 쓰잖슴. 그런거임.

#### 변수 정의

`int a = 10;` 이건 생성과 동시에 대입  
`int a; a = 10;` 이건 생성 후에 대입  
정수형 변수와 실수형 변수로 나눠진다.  
정수형 변수: char, short, int, long  
실수형 변수: float, double, long double

#### #include <stdio.h>

일단 시작은 #include <stdio.h>로 간다. import하는거임.  
stdio.h는 표준입출력파일이며 scanf, printf등 기본적인 함수들이 정의되어 있다.
