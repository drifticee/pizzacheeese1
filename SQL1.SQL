--SELECT * FROM emp;

/*
SELECT *
FROM player;
*/

SELECT * FROM DEPT;


CREATE TABLE 고객 (
번호 NUMBER(5) PRIMARY KEY,
이름 VARCHAR2(20) NOT NULL,
전화번호 VARCHAR2(15) UNIQUE,
성별 CHAR(4) CHECK(성별 IN ('남자', '여자')),
주소 VARCHAR2(30)
);

SELECT * FROM 고객;

INSERT INTO 고객 VALUES(1, '홍길동', '1234', '남자', '서울');
--INSERT INTO 고객 VALUES(2, '박길동', '1234', '여자', '인천');

SELECT ename 이름, sal 급여, sal*2+500 "Result"
FROM emp;

SELECT '선수이름', player_name, 'team_id', team_id, 100
FROM player;

SELECT ename + job FROM emp;

SELECT ename || job
FROM emp;

SELECT ename || ' (' || empno || ')' "사원이름(사원번호)"
FROM emp;

SELECT ename AS NAME, sal*7 "7sal"
FROM emp;

SELECT DISTINCT deptno, job
FROM emp;

SELECT DISTINCT team_id
FROM player;

--WHERE 조건식

SELECT ename, deptno, sal
FROM emp
WHERE sal >= 3000;

SELECT ename, deptno, sal
FROM emp
WHERE 1000 = 3000;

SELECT ename, deptno, sal
FROM emp
WHERE ename = 'sCOTT';

SELECT ename, deptno, sal
FROM EMP
WHERE deptno = 10 AND sal > 2500;

--exercise

SELECT player_name, position, height
FROM player
WHERE position = 'GK';

SELECT player_name, height, team_id, position
FROM PLAYER
WHERE height >= 192;

SELECT player_name, height, position
FROM PLAYER
WHERE position = 'GK' AND height > 190;

SELECT player_name, height
FROM PLAYER
WHERE height BETWEEN 190 AND 194;

--주의
SELECT player_name, height
FROM player
WHERE height BETWEEN 194 AND 190;

SELECT player_name
FROM player
WHERE player_name > '박길동';

SELECT player_name
FROM PLAYER p
WHERE player_name BETWEEN '나길동' AND '박길동';

SELECT player_name, height, team_id
FROM PLAYER
WHERE height = 195 OR height = 196 OR height = 165;

SELECT player_name, height, team_id
FROM PLAYER
WHERE height = ANY(195, 196, 165);

SELECT player_name, height, team_id
FROM player
WHERE height IN (195, 196, 165);

--_ 1글자, % 0~ 글자
SELECT player_name, e_player_name
FROM PLAYER
WHERE player_name LIKE '가%';

SELECT player_name, e_player_name
FROM player
WHERE player_name LIKE '_수%';

SELECT player_name, e_player_name
FROM player
WHERE player_name LIKE '__';

SELECT player_name, e_player_name
FROM player
WHERE e_player_name LIKE '%T%';

SELECT player_name, e_player_name
FROM player
WHERE e_player_name LIKE '%\%%' ESCAPE '\';

SELECT ename, sal, comm
FROM emp
WHERE comm > 200;

SELECT ename, sal, comm
FROM emp
WHERE comm <= 200;

--연산 우선순위 (), NOT, AND, OR

SELECT ename, sal FROM EMP
WHERE NOT sal BETWEEN 1000 AND 3000;

SELECT ename, sal FROM emp
WHERE sal NOT BETWEEN 1000 AND 3000;


--ename에 A 문자 없는 사원의 이름, 급여 조회
SELECT ename, sal FROM emp
WHERE NOT ename LIKE '%A%';

--player 키가 170 미만 194 초과인 선수들의 이름, 키 조회
SELECT player_name, height FROM PLAYER
WHERE height NOT BETWEEN 170 AND 194;

--player 영문이름에 e 2번만 나오는 선수들 한글이름, 영문이름 조회
SELECT player_name, e_player_name FROM PLAYER
WHERE e_player_name LIKE '%e%e%'
AND e_player_name NOT LIKE '%e%e%e%';

--GK 포지션인 선수중 소속팀이 K01팀이거나 키가 185보다 작은 선수들 이름, 포지션, 팀id, 키 조회
SELECT player_name, position, team_id, height FROM player
WHERE position = 'GK' AND (team_id = 'K01' OR height < 185);

SELECT player_name, position FROM player
WHERE NOT position = SOM0E('GK', 'MF', 'FW', 'DF');

--정렬

SELECT ename, deptno, sal
FROM EMP
ORDER BY deptno, ename DESC, sal;

-- order by에 숫자로 작성 : select 절의 n번째 항목으로 정렬
SELECT ename NAME, sal*12 newsal, (sal*12)+500 결과
FROM emp
WHERE sal*12 > 12345
ORDER BY NAME, 2 DESC nulls first; -- = name 오름차순, newsal 내림차순으로 정렬, NULL 값들 맨 앞으로 (마지막으로는 last)


--function