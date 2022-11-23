SELECT name FROM people
join stars on stars.person_id = people.id
join movies on movies.id = stars.movie_id
WHERE movies.id IN (
SELECT movies.id FROM movies
join stars on stars.movie_id = movies.id
join people on people.id = stars.person_id
WHERE name = "Kevin Bacon" AND birth = 1958)
AND name != "Kevin Bacon";