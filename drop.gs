drop.(a,[])=0
drop.(a,(x::xs)) | 1+drop.(a,xs)  = a==x  = 