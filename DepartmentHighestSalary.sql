/* Problem 184. Department Highest Salary
 * https://leetcode.com/submissions/detail/565367470/
 * 1. 문제:
 *   각 부서(DEPARTMENT)에서 가장 연봉(EMPLOYEE.SALARY)이 높은 사람들을 출력하여라.
 *   단 같은 부서 내에 연봉이 높은 사람이 둘 이상이면 모두 출력한다.
 *
 * 2. 아이디어:
 *   부서별로 max를 구한 subquery를 semi join
 * */
SELECT D.NAME DEPARTMENT, E.NAME EMPLOYEE, E.SALARY SALARY
FROM DEPARTMENT D, EMPLOYEE E
WHERE E.DEPARTMENTID = D.ID
AND E.SALARY = (SELECT MAX(EE.SALARY) FROM EMPLOYEE EE WHERE D.ID = EE.DEPARTMENTID);