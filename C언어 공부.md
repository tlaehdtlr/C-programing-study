### VS

- F7 컴파일
- ctrl + F5 실행
- 파일 변화
  - hello.c -> hello.obj -> hello.exe



### Debug

- 디버깅
  - 중단점 삽입/삭제 F9
  - 디버깅시작 F5
  - 중지 shift F5
  - 프로시저 단위 실행 F10
  - 한 단계씩 코드 실행 F11



### 자료형

여기 보면서 느낀 점은 window 32bit, 63bit 에 따라 sizeof 찍었을 때, 크기가 달라

이거 잘 생각하면서 해야하는건가



#### 정수

- char는 1바이트 정수라고 생각하면됨
- int
  - signed int, int
  - unsigned int, unsigned
    - 음수 아닌 정수
- short
  - signed short int ,  short
  - unsigned short int, unsigned short
- long
  - signed long int , long
  - unsigned long int , unsigned long
  - %ld
- long long
  - %lld

- unsigned 는 %u 를 사용함 (%lu %llu)
- 최대, 최소 넘으면 오버플로우, 언더플로우 발생함
- sizeof 사용!! ex) sizeof 188888;   괄호도 가능 sizeof (char) 
- 자료의 최대 최소 사용
  - #include <limits.h>
  - CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN (MAX도 가능 unsign 가능)
- 크기가 표시된 자료형
  - int8_t , int16_t , int32_t , int64_t



 #### 실수

- float (4바이트, 유효 7)   %f

- double (8, 16)    $f

- long double (8, 16)    $Lf

- 실제 c 표준은 유효자리 float 6, double 이 10

- ex.

  - ```
    float num1 = 0.1f;
    double num2 = 123.4567890;
    long double num3 = 5.4321l;
    ```

  - long 은 저렇게 숫자 뒤에 `l` 붙임

  - float num1 = .1f 이렇게도 가능

- 지수 표기법

  - 2.1e2 , 3.e5f 
  - 2.1e-2
  - %e, %Le

- 실수도 최댓값, 최솟값 있다잉 
- 얘네는 오버플로우되면 inf이고, 언더플로우되면 -inf 임



#### 문자

- char
- 1바이트 정수형임
- 문자에 해당하는 ASCII 코드 저장
- 작은 따옴표는 문자 2개 이상 묶을 수 없다



#### 상수

- const
- const int num = 10;
- 상수는 선언이랑 초기화 같이 해야함



#### 리터럴

- 값 그 자체
- 정수 리터럴 접미사가 있음 (나중에 이거 출력할 때, 쓸 수 있는듯?)



### 입출력

- 입력
  - getchar()
  - gets() , gets_s()
- 콘솔 입출력
  - standard input, stdin
  - standard output, stdout
- scanf(서식, 변수주소)
  - 표준입력으로 사용자 입력 받는 함수
  - stdio.h 에 있음
  - 이게 근데 뭔 컴파일 쪽에서 에러가 나나봐
    - #define _CRT_SECURE_NO_WARNINGS 써야해
    - 아니면 scanf_s 이거를 써도 되는듯
    - 아니 걍 scanf_s 쓰는게 좋은거 같다
      - 문자열의 경우 크기까지 붙여줌
        - scanf_s("%s", name, sizeof(name)) 
  - scanf("%d %d", &num1, &num2);
  - 문자열은 그냥 받음 scanf("%s", strname);
  - 단일 문자랑 문자열은 변수 뒤에 크기 넣어줄 것





### 덧뺄 곱나

- += , -= : 사용가능 굿

- ++ , -- : 1 증감
  
  - 포인터 연산에서 자료형 크기만큼 증감 가능
  
- ```c
  5/3 == 1
  5%3 == 2
  
  5.0/4.0 == 1.250000
  printf("%.2f", 5.0/4.0) // 1.25
  ```

  



### 선택문

#### if

````c
int num;
scanf("%d", &num);
if (num>0)
{
	printf("양수");
} else if (num<0)
{
	printf("음수");
} else
{
	printf('0')
}
````

#### switch

```c
int score;
scanf("%d", &score);
switch (score/10){
    case10:
    case 9:
        printf("A학점\n");
        break
    case 8:
        printf("B학점\n");
        break
       
    ....
	default:
        printf("F");
        break;
}
```



#### goto

- goto 문 만나면 label 위치로 무조건 이동
- 반복문 바로 벗어나게 함 (break, 여러번 안해도됨, 근데 이거 잘 안쓰는게 좋다네)
- 이거 써본 결과 별로임 쓰지마
- return 잘 써 그냥





### 연산자, 비트



### 반복

#### while

- 파이썬의 while과 같음

#### do-while

- 명령문을 먼저 실행 후 조건식 확인

#### for

- 반복횟수 정해져있음
- for(초기값; 조건식; 증감식;)
- 세미콜론 2개만 있으면 저기 인자? 들 생략 가능

#### 반복 제어

- break, continue 파이썬이랑 똑같음



### 포인터

- 메모리 (첫번째)주소를 참조
- 자료형 *변수명
  - 자료형은 포인터가 가리키는 곳의 값의 자료형임

```c
// 일반
int *p = 1;
int *p = NULL;

// 포인터 연산자 &(주소), *(주소에 저장된 값)
int a = 0;
int *p1 = &a;		//초기화할 때
*p1 = 123;		// a == 123이 됨
int *p2;	// 선언하고 할당이지
p = &a;


//다중 포인터
int a = 1;
int *p1 = &a;
int **p2 = &p1;

//1차원 배열과 포인터
int a[2] = {1,2};
int *b = a;
// b[0] == 1 이다
//포인터 연산
printf("%d", *(b+1)); // b[1]이므로 2 출력

// 포인터 배열 (원소에 값이 아닌 주소를 담을 수 있음)
int a=1, b=2, c=3;
int *p[3] = {&a, &b, &c};

*p[0] = 123;

// 다차원 배열
int a[2][3] = {0};
int (*pa)[3] = a;

int b[3][4][5];
int (*pb)[4][5];
```

- 포인터 함수

```c
#include <stdio.h>

void PrintValue(int a)
{
    printf("value = %d\n", a);
}

int main()
{
	void (*p_func)(int) = Printvalue;

    (*p_func)(5); 	//원칙
    p_func(5); 		// 허용

    return 0;	   
}    
```





### 메모리

- 정적 메모리 할당

  - ```
    char name[3][20] = {"김땡땡", "박땡땡", "이땡땡"}
    ```

    이러면 20 공간에 3글자만 들어가서 메모리 낭비 중

- 동적 메모리 할당

  - 포인터 변수 선언
    임의 공간 원하는 만큼 할당, 그 주소 포인터에 저장
    포인터를 이용하여 할당 받은 메모리 공간 사용
    다 쓰고 할당받은 메모리 해제하여 운영체제에 돌려줌

  - ```c
    #include <stdlib.h>
    char *str = NULL;
    str = (char*)malloc(20);
    strcpy(str, "안녕하세요");
    printf("%s \n", str);
    free(str);
    ```
    
  - malloc 사용

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    int main()
    {
        int *arr;
        int n;
    
        // 배열 크기 받기
        scanf("%d", &n);
        // int형 배열 n개 크기 만듦
        arr = (int*)malloc(sizeof(int)*n);
        // n개 수 배열에 저장
        for (int i=0; i<n; i++) scanf("%d", &arr[i]);
        
        for (int i=0; i<n; i++) printf("%d \n", arr[i]);
        
        // 동적할당 해제 (프린트 하고 나서 다~ 쓰고 해제해줘라)
        free(arr);        
    }
    ```

  - malloc 사용 2차원 배열 생성 코드

    ```c
    #include <stdio.h>
    #include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
    void input_value(int **arr, int row, int col);
    void output_value(int **arr, int row, int col);
    
    int main(void)
    {
    	int row, col;
    	scanf("%d %d", &row, &col);
    
    	int **arr = malloc(sizeof(int *) * row);   
    	/* 이중 포인터에 (int 포인터 크기 * row)만큼
    	동적 메모리 할당. 배열의 세로 */
    
    	for (int i = 0; i < row; i++)            // 세로 크기만큼 반복
    	{
    		arr[i] = malloc(sizeof(int) * col);    
    		// (int의 크기 * col)만큼 동적 메모리 할당. 배열의 가로
    	}
    
    	input_value(arr, row, col);
    	output_value(arr, row, col);
    
    	for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
    	{
    		free(arr[i]);            // 2차원 배열의 가로 공간 메모리 해제
    	}
    
    	free(arr);    // 2차원 배열의 세로 공간 메모리 해제
    
    	return 0;
    }
    
    void input_value(int **arr, int row, int col)
    {
    	for (int i = 0; i < row; i++)
    	{
    		for (int j = 0; j < col; j++)
    		{
    			scanf("%d", &arr[i][j]);
    		}
    	}
    }
    
    void output_value(int **arr, int row, int col)
    {
    	for (int i = 0; i < row; i++)
    	{
    		for (int j = 0; j < col; j++)
    		{
    			printf("%d ", arr[i][j]);
    		}
    		printf("\n");
    	}
    }
    ```

    






- 메모리 관련 함수들

  - memset(포인터, 값, 바이트 수);
    - 포인터가 가리키는 주소부터 바이트수 만큼을 값으로 채움
    - 메모리 할당 받고 초기화 해주는 습관!!
  - memcpy(받은 포인터, 복사할 값 들어있는 주소, 바이트수);
    - 2차 배열 복사할 때 strcpy()는 여러번 사용해야는데 이거 하번이면 됨
  - 





### 배열

- 자료형 동일한 데이터들 모음
- 크기를 지정해준다
- int numbers[10];
- 인덱스는 0부터 시작임 파이썬이랑 같음

##### 2차원 배열 생성과 프린트 내 코드

- ```c
  #include <stdio.h>
  #include <stdlib.h>   
  void input_value(int **arr, int row, int col);
  void output_value(int **arr, int row, int col);
  
  int main(void)
  {
  	int row, col;
  	scanf("%d %d", &row, &col);
  
  	int **arr = malloc(sizeof(int *) * row);   
  
  	for (int i = 0; i < row; i++)          
  	{
  		arr[i] = malloc(sizeof(int) * col);    
  	}
  
  	input_value(arr, row, col);
  	output_value(arr, row, col);
  
  	for (int i = 0; i < row; i++)    
  	{
  		free(arr[i]);           
  	}
  
  	free(arr);   
  
  	return 0;
  }
  
  void input_value(int **arr, int row, int col)
  {
  	for (int i = 0; i < row; i++)
  	{
  		for (int j = 0; j < col; j++)
  		{
  			scanf("%d", &arr[i][j]);
  		}
  	}
  }
  
  void output_value(int **arr, int row, int col)
  {
  	for (int i = 0; i < row; i++)
  	{
  		for (int j = 0; j < col; j++)
  		{
  			printf("%d ", arr[i][j]);
  		}
  		printf("\n");
  	}
  }
  
  void clear_arr(int **arr, int row, int col)
  {
  	for (int i = 0; i < row; i++)
  	{
  		for (int j = 0; j < col; j++)
  		{
  			arr[i][j] = 0;
  		}
  	}
  }
  ```

- 

#### 문자열

- null 문자로 끝나는 단일문자의 연결
- null은 아스키코드 0 , char abc = '\0', char abd[10] = "\0"
- 문자열 복사
  - #include <string,h>
  - strcpy(문자열 담을 변수명, 담길 문자열 값)
  - strcpy_s 가 권장됨
  - strnspy(문자열 담을 변수명, 담을 문자열 값, 담을 크기)

- 문자열 길이
  - strlen(문자열)
    - 개행문자까지 세지 않은 것임
    - 실제 길이는 개행문자 포함이라서 +1
  - 길이 비교
    - strcmp(문자열1, 문자열2)
      - 아스키 코드값으로 변환하여 차례대로 비교
      - 1이 크면 음수, 같으면 0, 2가 크면 양수 반환
    - stricmp(문1, 문2)
      - 대소문자 구분 x



### 구조체

```c
struct score
{
    int scoreKOR;
    int scoreMAT;
    int scoreENG;
}

void main()
{
    // 선언
    struct score a;
    // 초기화 가능
    struct score a = {100, 75, 85};
	// 구조체 내의 변수에 접근법
    a.scoreMAT = 100;
    
    // 배열로 선언
    struct score b[10];
    
    b[0].scoreKOR = 10;    
    b[1].scoreKOR = 50;
    
    // 포인터 선언
    struct score *p;
    
    // 포인터 변수로 가능하지
    p = &a;
    p = b;
    //다만 변수 접근이 달라
    p->scoreKOR = 50;
        
}
```

- 선언 쉽게

```c
typedef struct score
{
	int scoreKOR;
} SCORE;

void main()
{
    SCORE a;
}
```







### 함수

- 파이썬이랑 비슷한데 리턴 타입이랑 인자 타입 정해주는 것 잊지말고, 선언을 먼저하네
- 그냥 쓰면 값에 의한 호출이고,
- `&` 이거를 앞에 붙이면 참조에 의한 호출이 됨
  - 함수 정의할 때 인자에 자료형* 이런식으로 * 이거 붙여줘야해
  - 포인터(주소) 자료형으로 쓸 수 있게

- ##### 함수 선언부 매크로
  - http://jake.dothome.co.kr/attr1/
  - `__weak`
    - 링크 시, 다른 곳에 같은 이름의 strong symbol이 존재하면 이거 대신 strong 쓴다

- 콜백 함수

  - 사용자들이 호출하는 함수가 API인데, 이때 사용자가 작성한 함수를 API가 호출하게 하기 위해 콜백함수를 써야함
  - 포인터 함수를 이용해준다
    - 예제가 잘 나옴 https://pang2h.tistory.com/243





### 매크로

- 컴파일러에 특정 작업을 지시하는 전처리기(preprocessor)를 제공
  보통 전처리기는 반복되는 값이나 작업을 미리 정의할 때, 사용하며 컴파일 옵션 설정이나 조건부 컴파일도 가능

- define은 컴파일 직전에 처리됨, 전처리 과정 이후에 바뀜

- https://dojang.io/mod/page/view.php?id=651 참고하셈

- 변수 설정

  - ```c
    #include <stdio.h>
    #define ARRAY_SIZE 10    // 10을 ARRAY_SIZE로 정의
    
    int main()
    {
        char s1[ARRAY_SIZE];    // 10 대신 ARRAY_SIZE 매크로 사용
    
        for (int i = 0; i < ARRAY_SIZE; i++)    // 10 대신 ARRAY_SIZE 매크로 사용
        {
            s1[i] = 97 + i;
        }
    
        for (int i = 0; i < ARRAY_SIZE; i++)    // 10 대신 ARRAY_SIZE 매크로 사용
        {
            printf("%c ", s1[i]);
        }
    
        return 0;
    }
    ```

- 함수 모양 매크로

  - 이거 개꿀인가 귀찮은 것들 다 한방컷인데?

    ```c
    #include <stdio.h>
    
    #define PRINT_NUM(x) printf("%d\n", x)    // printf("%d\n", x)를 PRINT_NUM(x)로 정의
    
    int main()
    {
        PRINT_NUM(10);    // 10: printf("%d\n", 10)
    
        PRINT_NUM(20);    // 20: printf("%d\n", 20)
    
        return 0;
    }
    ```

  - 요거 여러 줄도 가능해. 근데 조건문이랑 반복문 쓸 때, 중괄호 잘 써줘야해 잊지마!!!



#### 이외 전처리기 (#if, #else, #endif, #ifdef, #ifndef, #undef)

-  #if , # endif

  - ```c
    #define a 10
    
    void main()
    {
        #if a == 10
        printf("이것만 출력");
        #elif a ==20
        printf("어림없지");
        #else
        printf("둘다아님");
        #endif        
    }
    ```

  - 이 때 조건식에는 변수 쓰면 안됨

    ```c
    #define a 10
    
    void main()
    {
        int b = 10;
        #if a == b
        printf("이것만 출력");
        #elif a == b+10
        printf("어림없지");
        #else
        printf("둘다아님");
        #endif        
    }
    ```

  - 근데 밑에 명령문에는 가능함

    ```c
    #define a 10
    
    void main()
    {
        int b = 10;
        #if a == b
        printf("%d 이것만 출력", b);
        #elif a == b+10
        printf("어림없지");
        #else
        printf("둘다아님");
        #endif        
    }
    ```

- #ifdef

  - 매크로 정의되어있는지만 따짐

  - ```c
    #define test
    
    void main()
    {
        #ifdef test
        printf("정의돼있네");
        #else
        printf("안됨");
        #endif        
    }
    ```

- #endif 

  - 여기 밑에 중괄호로 넣어서 디버깅 용이하게 하는거 같은데 일단 잘 모르겠으면 찾아보던가 나는 지금 피곤하다

- #ifndef

  - if not define 임

- #undef

  - 앞에 define 한거 취소

- 헤더파일 중복 방지로 #ifndef 가 쓰이나봐

  - ```c
    #ifndef test
    #define test
    #endif
    ```



### 인라인 함수

- 함수 선언 시 inline

- 매크로 함수는 치환이고, 함수는 스택으로 불림

- 매크로 함수 단점 보완하고자 일반 함수 성향 빌려옴

- 컴파일러가 인라이닝하는게 이득이면 치환 / 아니면 일반 함수처럼 동작

- ```c
  #define MUL(a,b) ((a)*(b))
   
  #define MAX(a,b) ((a)>(b)?(a):(b))
   
  using namespace std;
   
  inline int func_mul(int a, int b){
      return a*b;
  }
  inline int func_max(int a, int b){
      return a>b?a:b;
  }
  ```

- 



### 모듈화

