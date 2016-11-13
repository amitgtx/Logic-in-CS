belongs(X,[X | List]).
belongs(X,[Z | List]):-belongs(X,List).
myAppend(X,[ ],X).
myAppend([ ],Y,Y).
myAppend([H | R],Y,[H | New]):-myAppend(R, Y, New).
my_m(X,Y):-[H|T]=Y,(X=H;my_m(X,T)).
