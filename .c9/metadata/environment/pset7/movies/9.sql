{"filter":false,"title":"9.sql","tooltip":"/pset7/movies/9.sql","undoManager":{"mark":22,"position":22,"stack":[[{"start":{"row":0,"column":0},"end":{"row":7,"column":36},"action":"insert","lines":["SELECT name FROM people","WHERE id IN (","    SELECT person_id","    FROM stars","    WHERE movie_id IN(","        SELECT id","        FROM movies","        WHERE title = 'Toy Story'));"],"id":1}],[{"start":{"row":7,"column":18},"end":{"row":7,"column":19},"action":"remove","lines":["e"],"id":2},{"start":{"row":7,"column":17},"end":{"row":7,"column":18},"action":"remove","lines":["l"]},{"start":{"row":7,"column":16},"end":{"row":7,"column":17},"action":"remove","lines":["t"]},{"start":{"row":7,"column":15},"end":{"row":7,"column":16},"action":"remove","lines":["i"]},{"start":{"row":7,"column":14},"end":{"row":7,"column":15},"action":"remove","lines":["t"]}],[{"start":{"row":7,"column":14},"end":{"row":7,"column":15},"action":"insert","lines":["y"],"id":3},{"start":{"row":7,"column":15},"end":{"row":7,"column":16},"action":"insert","lines":["e"]},{"start":{"row":7,"column":16},"end":{"row":7,"column":17},"action":"insert","lines":["a"]},{"start":{"row":7,"column":17},"end":{"row":7,"column":18},"action":"insert","lines":["r"]}],[{"start":{"row":7,"column":31},"end":{"row":7,"column":32},"action":"remove","lines":["'"],"id":4},{"start":{"row":7,"column":30},"end":{"row":7,"column":31},"action":"remove","lines":["y"]},{"start":{"row":7,"column":29},"end":{"row":7,"column":30},"action":"remove","lines":["r"]},{"start":{"row":7,"column":28},"end":{"row":7,"column":29},"action":"remove","lines":["o"]},{"start":{"row":7,"column":27},"end":{"row":7,"column":28},"action":"remove","lines":["t"]},{"start":{"row":7,"column":26},"end":{"row":7,"column":27},"action":"remove","lines":["S"]},{"start":{"row":7,"column":25},"end":{"row":7,"column":26},"action":"remove","lines":[" "]},{"start":{"row":7,"column":24},"end":{"row":7,"column":25},"action":"remove","lines":["y"]},{"start":{"row":7,"column":23},"end":{"row":7,"column":24},"action":"remove","lines":["o"]},{"start":{"row":7,"column":22},"end":{"row":7,"column":23},"action":"remove","lines":["T"]},{"start":{"row":7,"column":21},"end":{"row":7,"column":22},"action":"remove","lines":["'"]}],[{"start":{"row":7,"column":21},"end":{"row":7,"column":22},"action":"insert","lines":["y"],"id":5},{"start":{"row":7,"column":22},"end":{"row":7,"column":23},"action":"insert","lines":["e"]},{"start":{"row":7,"column":23},"end":{"row":7,"column":24},"action":"insert","lines":["a"]},{"start":{"row":7,"column":24},"end":{"row":7,"column":25},"action":"insert","lines":["r"]}],[{"start":{"row":7,"column":24},"end":{"row":7,"column":25},"action":"remove","lines":["r"],"id":6},{"start":{"row":7,"column":23},"end":{"row":7,"column":24},"action":"remove","lines":["a"]},{"start":{"row":7,"column":22},"end":{"row":7,"column":23},"action":"remove","lines":["e"]},{"start":{"row":7,"column":21},"end":{"row":7,"column":22},"action":"remove","lines":["y"]}],[{"start":{"row":7,"column":21},"end":{"row":7,"column":22},"action":"insert","lines":["2"],"id":7},{"start":{"row":7,"column":22},"end":{"row":7,"column":23},"action":"insert","lines":["0"]},{"start":{"row":7,"column":23},"end":{"row":7,"column":24},"action":"insert","lines":["0"]},{"start":{"row":7,"column":24},"end":{"row":7,"column":25},"action":"insert","lines":["4"]}],[{"start":{"row":7,"column":27},"end":{"row":7,"column":28},"action":"insert","lines":[" "],"id":8}],[{"start":{"row":7,"column":28},"end":{"row":7,"column":29},"action":"insert","lines":["O"],"id":9},{"start":{"row":7,"column":29},"end":{"row":7,"column":30},"action":"insert","lines":["R"]},{"start":{"row":7,"column":30},"end":{"row":7,"column":31},"action":"insert","lines":["D"]},{"start":{"row":7,"column":31},"end":{"row":7,"column":32},"action":"insert","lines":["E"]},{"start":{"row":7,"column":32},"end":{"row":7,"column":33},"action":"insert","lines":["R"]}],[{"start":{"row":7,"column":33},"end":{"row":7,"column":34},"action":"insert","lines":[" "],"id":10},{"start":{"row":7,"column":34},"end":{"row":7,"column":35},"action":"insert","lines":["B"]},{"start":{"row":7,"column":35},"end":{"row":7,"column":36},"action":"insert","lines":["Y"]}],[{"start":{"row":7,"column":36},"end":{"row":7,"column":37},"action":"insert","lines":[" "],"id":11}],[{"start":{"row":7,"column":37},"end":{"row":7,"column":38},"action":"insert","lines":["Y"],"id":12}],[{"start":{"row":7,"column":37},"end":{"row":7,"column":38},"action":"remove","lines":["Y"],"id":13}],[{"start":{"row":7,"column":37},"end":{"row":7,"column":38},"action":"insert","lines":["y"],"id":14},{"start":{"row":7,"column":38},"end":{"row":7,"column":39},"action":"insert","lines":["e"]},{"start":{"row":7,"column":39},"end":{"row":7,"column":40},"action":"insert","lines":["a"]},{"start":{"row":7,"column":40},"end":{"row":7,"column":41},"action":"insert","lines":["r"]}],[{"start":{"row":0,"column":0},"end":{"row":7,"column":42},"action":"remove","lines":["SELECT name FROM people","WHERE id IN (","    SELECT person_id","    FROM stars","    WHERE movie_id IN(","        SELECT id","        FROM movies","        WHERE year = 2004)) ORDER BY year;"],"id":15},{"start":{"row":0,"column":0},"end":{"row":7,"column":43},"action":"insert","lines":["SELECT name FROM people","WHERE id IN (","    SELECT person_id","    FROM stars","    WHERE movie_id IN(","        SELECT id","        FROM movies","        WHERE year = 2004 ORDER BY year)) ;"]}],[{"start":{"row":0,"column":7},"end":{"row":0,"column":8},"action":"insert","lines":["S"],"id":16},{"start":{"row":0,"column":8},"end":{"row":0,"column":9},"action":"insert","lines":["I"]}],[{"start":{"row":0,"column":8},"end":{"row":0,"column":9},"action":"remove","lines":["I"],"id":17},{"start":{"row":0,"column":7},"end":{"row":0,"column":8},"action":"remove","lines":["S"]}],[{"start":{"row":0,"column":7},"end":{"row":0,"column":8},"action":"insert","lines":["D"],"id":18},{"start":{"row":0,"column":8},"end":{"row":0,"column":9},"action":"insert","lines":["I"]},{"start":{"row":0,"column":9},"end":{"row":0,"column":10},"action":"insert","lines":["S"]},{"start":{"row":0,"column":10},"end":{"row":0,"column":11},"action":"insert","lines":["T"]},{"start":{"row":0,"column":11},"end":{"row":0,"column":12},"action":"insert","lines":["I"]},{"start":{"row":0,"column":12},"end":{"row":0,"column":13},"action":"insert","lines":["N"]},{"start":{"row":0,"column":13},"end":{"row":0,"column":14},"action":"insert","lines":["C"]},{"start":{"row":0,"column":14},"end":{"row":0,"column":15},"action":"insert","lines":["T"]}],[{"start":{"row":0,"column":15},"end":{"row":0,"column":16},"action":"insert","lines":[" "],"id":19}],[{"start":{"row":0,"column":15},"end":{"row":0,"column":16},"action":"remove","lines":[" "],"id":20}],[{"start":{"row":0,"column":15},"end":{"row":0,"column":16},"action":"insert","lines":[" "],"id":21}],[{"start":{"row":0,"column":1},"end":{"row":7,"column":43},"action":"remove","lines":["ELECT DISTINCT name FROM people","WHERE id IN (","    SELECT person_id","    FROM stars","    WHERE movie_id IN(","        SELECT id","        FROM movies","        WHERE year = 2004 ORDER BY year)) ;"],"id":22},{"start":{"row":0,"column":0},"end":{"row":0,"column":1},"action":"remove","lines":["S"]}],[{"start":{"row":0,"column":0},"end":{"row":7,"column":42},"action":"insert","lines":["SELECT name FROM people","WHERE id IN (","    SELECT person_id","    FROM stars","    WHERE movie_id IN(","        SELECT DISTINCT id","        FROM movies","        WHERE year = 2004 ORDER BY year));"],"id":23}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":0,"column":0},"end":{"row":7,"column":42},"isBackwards":true},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1583872743596,"hash":"f344cf1458e6b05ab1bac7a723de1188c5193f70"}