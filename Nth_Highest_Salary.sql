/* Problem 177. Nth Highest Salary
 * https://leetcode.com/submissions/detail/565385116/
 * 1. 문제:
 *   중복을 제외하고 n번째로 높은 연봉을 return하라.
 *
 * 2. 아이디어:
 *   중복을 제외하기 위해 group by, 순서를 맞추기 위해 order by를 넣고 rownum으로 번호를 매긴 뒤 바깥에서 입력된 N으로 filter 처리
 * */
CREATE FUNCTION getNthHighestSalary(N IN NUMBER)
RETURN NUMBER
IS
    result NUMBER;
BEGIN
    SELECT SALARY INTO result
    FROM (SELECT ROWNUM RN, SALARY
        FROM (SELECT SALARY FROM EMPLOYEE
            GROUP BY SALARY
            ORDER BY SALARY DESC))
    WHERE RN = N;
    RETURN result;
END;