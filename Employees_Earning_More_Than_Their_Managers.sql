/* Problem 181. Employees Earning More Than Their Managers
 * https://leetcode.com/submissions/detail/565370990/
 * 1. 문제:
 *   자신의 상관보다 연봉이 높은 사람들을 출력하여라.
 *   자신의 상관은 MANAGERID로 나타내며, 이 MANAGERID에 대응되는 ID가 상관이다.
 *
 * 2. 아이디어:
 *   self join
 * */
SELECT E1.NAME EMPLOYEE
FROM EMPLOYEE E1, EMPLOYEE E2
WHERE E1.SALARY > E2.SALARY
AND E1.MANAGERID = E2.ID