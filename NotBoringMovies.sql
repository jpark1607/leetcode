/* Problem 620. Not Boring Movies
 * https://leetcode.com/problems/not-boring-movies/submissions/
 * 1. 문제:
 *   ID가 홀수인 영화 중에 지루(boring)하지 않은 영화들을 높은 평점 순으로 출력하여라.
 *
 * 2. 아이디어:
 *   홀수는 MOD로 판단하고, 높은 평점은 ORDER BY DESC를 사용한다.
 * */
SELECT * FROM CINEMA
WHERE MOD(ID, 2) = 1
AND DESCRIPTION <> 'boring'
ORDER BY RATING DESC;