/* Problem 175. Combine Two Tables
 * https://leetcode.com/submissions/detail/565362759/
 * 1. 문제:
 *   PERSONID가 UNIQUE할 때, PERSON.FIRSTNAME, PERSON.LASTNAME, ADDRESS.CITY, ADDRESS.STATE를 출력하라.
 *   단, ADDRESS에 없는 PERSONID일 경우 ADDRESS.CITY, ADDRESS.STATE는 NULL로 출력한다.
 *
 * 2. 아이디어:
 *   outer join
 * */
SELECT P.FIRSTNAME, P.LASTNAME, A.CITY, A.STATE
FROM PERSON P, ADDRESS A
WHERE P.PERSONID = A.PERSONID(+);