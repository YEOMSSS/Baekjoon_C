좋습니다 🙆‍♂️ “순정 C에서 꼭 배우고 자주 쓰이는 기본 패턴 5개”를 파이썬과 비교하면서 정리해 드릴게요.
(이거 익히면 C 입문 코스 대부분 커버됩니다!)

📌 순정 C 핵심 패턴 5개

1. 입출력 (I/O)

파이썬

x = int(input())
print(x)

C

#include <stdio.h>

int main() {
int x;
scanf("%d", &x); // 입력
printf("%d\n", x); // 출력
return 0;
}

👉 차이점: scanf는 변수 주소(&x)를 줘야 함 (값이 아니라 “저장할 위치”).

2. 배열(Array)

파이썬

arr = [1, 2, 3, 4, 5]
print(arr[2]) # 3

C

int arr[5] = {1, 2, 3, 4, 5};
printf("%d\n", arr[2]); // 3

👉 차이점: 크기를 반드시 지정해야 하고, 자료형(int/char 등)을 명시해야 함.

3. 함수(Function)

파이썬

def add(a, b):
return a + b
print(add(2, 3))

C

int add(int a, int b) {
return a + b;
}

int main() {
printf("%d\n", add(2, 3));
return 0;
}

👉 차이점: C는 함수 앞에 반환형(int)과 매개변수 자료형을 꼭 써야 함.

4. 포인터(Pointer)

파이썬에는 없음. (모든 게 객체라 자동 관리됨)
C

#include <stdio.h>

int main() {
int x = 10;
int *p = &x; // p는 x의 주소를 가짐
printf("%d\n", *p); // p가 가리키는 값 → 10
return 0;
}

👉 포인터는 C의 핵심. 메모리 직접 접근, 배열·문자열 처리, 동적 할당 등에 필수.

5. 파일 입출력(File I/O)

파이썬

with open("data.txt", "w") as f:
f.write("Hello\n")

C

#include <stdio.h>

int main() {
FILE \*f = fopen("data.txt", "w"); // 파일 열기
fprintf(f, "Hello\n"); // 파일에 쓰기
fclose(f); // 닫기
return 0;
}

👉 FILE \* 포인터로 파일을 제어. fprintf, fscanf, fgets 등 함수 사용.

✅ 정리

입출력: scanf/printf

배열: 크기 고정, 자료형 명시

함수: 반환형 + 매개변수 타입 필수

포인터: C의 꽃, 메모리 직접 제어

파일 입출력: FILE\* + fopen/fclose
