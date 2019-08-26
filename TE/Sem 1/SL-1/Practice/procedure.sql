create procedure print_prime(in lim int) 
begin 
declare no int default 2; 
declare i int default 0; 
declare flg int default 0; 
while no<lim do 
set flg = 0;
set i=2; 
while i<=no/2 do 
if mod(no,i) = 0 then 
set flg = 1; 
end if; 
set i=i+1; 
end while; 
if flg = 0 then 
select no; 
end if; 
set no=no+1; 
end while; 
end;$
