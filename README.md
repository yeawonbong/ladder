# ladder

random ladder generator

실행시마다 랜덤으로 사다리가 출력되며, 세번째 인자 `start` 입력 시 왼쪽으로부터 `start`번째 출발지점의 경로가 표시되어 출력된다.

## 실행방법

- 컴파일: `make`
    - 실행파일 삭제: `make clean`
    - 삭제 후 재실행: `make re`
- 실행: `./ladder ( [col] [lv] [start] )`
- `col`, `lv` 는 기본 초기값으로 설정되어 실행되며, 
`start` 인자는 미입력 시 경로 결과(길찾기)가 반영되지 않은 기본 사다리만 출력된다.
- 모든 인자는 자연수만 입력이 가능하다.

## 인자 설명

- `col` (optional) : 사다리의 세로막대 수 (1 < col ≤ 100, default: 10)
- `lv` (optional) : 복잡도 레벨 1, 2, 3 선택, 사다리의 가로 막대가 1 < 2 < 3 순으로 많아진다. (default: 3)
- `start` (optional) : 결과를 조회할 시작점 세로막대 번호 (1 ≤ start ≤ col, default: none)

## 사용문자

```c
char* bars[16] = {
	  "├", "│", "┤", "──────────" //기본 얇은막대
	, "┣", "┃", "┫", "━━━━━━━━━━" //기본 굵은막대 (idx+4)
	, "┡", "┃", "┪", "          " //오른쪽으로 꺾을 때 (idx+8)
	, "┢", "┃", "┩"               //왼쪽으로 꺾을 때 (idx+12)
};
```

## 참고 (코드흐름)
![IMG_8813C31C06F1-1](https://github.com/yeawonbong/ladder/assets/75327385/771f7d09-12fd-41ad-8dfb-b66650a73913)

