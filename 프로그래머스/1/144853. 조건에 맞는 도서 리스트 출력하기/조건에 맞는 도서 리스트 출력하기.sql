SELECT book_id, substr(published_date, 1, 10) from book
where category = '인문' and substr(published_date, 1, 4) = 2021