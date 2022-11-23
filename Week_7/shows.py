# # sqlite3 shows.db
# # .schema to see what kinds of data is present 
# SELECT * FROM shows WHERE title = "The Office";
# SELECT * FROM shows WHERE title = "The Office" AND year = 2005;
# .timer on 
# SELECT * FROM shows WHERE title = "The Office";
# CREATE INDEX "title_index" ON "shows" ("title"); # do beter than linear search with an index. Creates a b-tree
# SELECT * FROM shows WHERE title = "The Office"; # Time was significatly lower, we just created an index

### Now to get info from across tables, how do we do that. We can join two tables together
# Shows have no mention of people, people no mention of shows. We need to use stars table to join the two - person id and show id

# So we need person_id to get show_id, then get back all show titles!
# select * from people where name = "Steve Carell";
# select id from people where name = "Steve Carell";
# SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Steve Carell");
# SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Steve Carell"));
# SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Steve Carell")) ORDER BY title;

# CREATE INDEX person_index ON stars (person_id);
# CREATE INDEX show_index ON stars (show_id);
# CREATE INDEX name_index ON people (name);

# SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Steve Carell")) ORDER BY title;

# time is much lower bc we created indexes for easier searching 

# to connect name to show id to show table
# lines up two tables

# SELECT title FROM people JOIN stars ON people.id = stars.person_id JOIN shows ON stars.show_id = shows.id WHERE name = "Steve Carell" ORDER BY title;

# We can do the same thing with one query what we needed 3 for earlier by using JOIN function

# new formatting
# sqlite> SELECT title FROM people, stars, shows
#    ...> WHERE people.id = stars.person_id
#    ...> AND stars.show_id = shows.id
#    ...> AND name = "Steve Carell";

# space vs time, find a balance





