bool lineIntersect(Line3D L1, Line3D L2) {
  Point3D s = L1.s-L1.e;
  Point3D e = L2.s-L2.e;
  Point3D p  = s*e;
  if (ZERO(p)) return false;	  //Parallel
  p = (L2.s-L1.e)*(L1.s-L1.e);
  return ZERO(p&L2.e);					//Common face
}
//Please check whether `$a$, $b$, $c$, $d$` on a plane first
bool segmentIntersect(Point a,Point b,Point c,Point d) {
  Point ret = (a-b)*(c-d);
  Point t1 = (b-a)*(c-a);
  Point t2 = (b-a)*(d-a);
  Point t3 = (d-c)*(a-c);
  Point t4 = (d-c)*(b-c);
  return sgn(t1&ret)*sgn(t2&ret) < 0 &&
         sgn(t3&ret)*sgn(t4&ret) < 0;
}
//Distance from point `$p$` to line `$L$`
double distance(Point3D p, Line3D L) {
  return (Norm((p-L.s)*(L.e-L.s))/Norm(L.e-L.s));
}
//Angle between line `$L_1$` and `$L_2$`, `$\theta\in[0,\pi]$`
double calcTheta(Line3D L1, Line3D L2) {
  Point3D u = L1.e - L1.s;
  Point3D v = L2.e - L2.s;
  return acos( (u & v) / (Norm(u)*Norm(v)) );
}
