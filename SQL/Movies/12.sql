SELECT DISTINCT m1.title
FROM movies m1
JOIN stars s1 ON m1.id = s1.movie_id
JOIN stars s2 ON m1.id = s2.movie_id
JOIN people p1 ON s1.person_id = p1.id
JOIN people p2 ON s2.person_id = p2.id
WHERE p1.name = 'Johnny Depp' AND p2.name = 'Helena Bonham Carter';
