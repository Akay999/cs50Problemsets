SELECT COUNT(title) AS number_of_movies FROM movies WHERE id = (SELECT movie_id FROM ratings WHERE rating = 10.0);