r(a,b).
r(a,c).
r(b,d).
r(c,d).
r(e,d).
edge(X,Y):-r(X,Y);r(Y,X).
path(X,Y):-edge(X,Y);edge(X,Z),path(Z,Y).
