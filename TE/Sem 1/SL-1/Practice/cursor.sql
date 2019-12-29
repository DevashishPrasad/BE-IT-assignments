create procedure run_cursor() 
begin 
	DECLARE name_list varchar(2000) DEFAULT "";
	DECLARE finished INTEGER DEFAULT 0; 
	DECLARE name varchar(30) DEFAULT ""; 

	DEClARE show_names CURSOR FOR SELECT ename FROM Employee; 
	DECLARE CONTINUE HANDLER  FOR NOT FOUND SET finished = 1; 
	
	OPEN show_names; 
	
	get_name: LOOP 	
		FETCH show_names INTO name; 
		IF finished = 1 THEN 
			LEAVE get_name; 
		END IF; 

		SELECT name;
		SET name_list = CONCAT(name,",",name_list);
	END LOOP get_name;
	SELECT name_list;
	CLOSE show_names;
END$
