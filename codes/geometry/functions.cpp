Point nearestPointToLine(Point P, Line L) {
  Point result;
  double a, b, t;
  a = L.e.x-L.s.x;
  b = L.e.y-L.s.y;
  t = ( (P.x-L.s.x)*a+(P.y-L.s.y)*b )/(a*a+b*b);
  if (t >= 0 && t <= 1) {
    result.x = L.s.x+a*t;
    result.y = L.s.y+b*t;
  }
  return result;
}
//Segment
bool inter(Line l1,Line l2) {
  return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.s)*(l1.e-l1.s))*sgn((l2.e-l1.s)*(l1.e-l1.s)) <= 0 &&
    sgn((l1.s-l2.s)*(l2.e-l2.s))*sgn((l1.e-l2.s)*(l2.e-l2.s)) <= 0;
}
bool onSeg(Line a,Point b) {
  return ((a.s-b)*(a.e-b) == 0 &&
          (b.x-a.s.x)*(b.x-a.e.x) <= 0 &&
          (b.y-a.s.y)*(b.y-a.e.y) <= 0);
}
int inPoly(Point p,Point poly[], int n) {
  int i, count;
  Line ray, side;
  count = 0;
  ray.s	= p;
  ray.e.y  = p.y;
  ray.e.x  = -1;//`$-\infty$`
  for (i = 0; i < n; i++) {
    side.s = poly[i];
    side.e = poly[(i+1)%n];
    if(OnSeg(p, side))
      return 1;
    if (side.s.y == side.e.y)
      continue;
    if (OnSeg(side.s, ray)) {
      if (side.s.y > side.e.y) count++;
    } else if (OnSeg(side.e, ray)) {
      if (side.e.y > side.s.y) count++;
    } else if (inter(ray, side)) {
      count++;
    }
  }
  return ((count % 2 == 1) ? 0 : 2);
}
Point centerOfPolygon(Point poly[],int n) {
  Point p, p0, p1, p2, p3;
  double m, m0;
  p1 = poly[0];
  p2 = poly[1];
  p.x = p.y = m = 0;
  for (int i = 2; i < n; i++) {
    p3 = poly[i];
    p0.x = (p1.x + p2.x + p3.x) / 3.0;
    p0.y = (p1.y + p2.y + p3.y) / 3.0;
    m0 = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x;
    if (cmp(m + m0,0.0) == 0)
      m0 += eps;
    p.x = (m * p.x + m0 * p0.x) / (m + m0);
    p.y = (m * p.y + m0 * p0.y) / (m + m0);
    m = m + m0;
    p2 = p3;
  }
  return p;
}
