/* Problem 183. Customers Who Never Order
 * https://leetcode.com/submissions/detail/565365502/
 * 1. 문제:
 *   주문 내역이 없는(ORDER.CUSTOMERID가 없는) CUSTOMER.NAME을 출력하라.
 *
 * 2. 아이디어:
 *   anti join
 * */
SELECT C.NAME AS CUSTOMERS
FROM CUSTOMERS C
WHERE C.ID NOT IN (SELECT O.CUSTOMERID FROM ORDERS O);
