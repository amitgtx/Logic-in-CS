edge(a,b).
edge(a,c).
edge(b,d).
edge(c,d).
edge(e,d).
path(X,Y):-edge(X,Y).
path(X,Y):-edge(X,Z),path(Z,Y).
