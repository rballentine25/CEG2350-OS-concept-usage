## Lab 05

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu
- Date: 10/3/2024

## Part 1 

Make sure the following files are in your GitHub repository
- validator (with commits for each step complete)
- `clean1.txt` through `clean4.txt`

## Part 2 Answers

1. `sed -E -i 's/<\/\w*>//g' sedfile.md`
2. `sed -E -i 's/\s{,4}<li>/- /g' sedfile.md`
3. `sed -i 's/<h1>/# /g' sedfile.md`
4. `sed -i 's/<h2>/## /g' sedfile.md`
5. `sed -E -i 's/<(ul|html)>//g' sedfile.md`
6. `sed -i 's/B/M/g' sedfile.md`

## Part 3 Answers

1. `awk /^Bil/ { print $1 } records.txt`
2. `awk '$4 ~ /42/ { print $3 }' records.txt`
3. `awk '$3 ~ /@wright\.edu/ { print $2 ", " $1 ": " $3 }' records.txt`
4. 
5.

## Extra Credit - Remove this if not doing

1. Source: 
    - Regular Expression Pattern: 
2. Pattern explanation:
3. Verify `validator2` is in your GitHub repository
