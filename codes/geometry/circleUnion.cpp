for (int i = 1; i <= n; i++)
  ans[i] = 0.0;
for (int i = 0; i < n; i++) {
  tote = 0;
  e[tote++] = Event(-pi,1);
  e[tote++] = Event(pi,-1);
  for (int j = 0; j < n; j++)
    if (j != i) {
      lab = Point(c[j].c.x-c[i].c.x,c[j].c.y-c[i].c.y);
      AB = lab.Length();
      AC = c[i].r;
      BC = c[j].r;
      if (cmp(AB+AC,BC) <= 0) {
        e[tote++] = Event(-pi,1);
        e[tote++] = Event(pi,-1);
        continue;
      }
      if (cmp(AB+BC,AC) <= 0) continue;
      if (cmp(AB,AC+BC) > 0)  continue;
      theta = atan2(lab.y,lab.x);
      fai = acos((AC*AC+AB*AB-BC*BC)/(2.0*AC*AB));
      a0 = theta-fai;
      if (cmp(a0,-pi) < 0)	a0 += 2*pi;
      a1 = theta+fai;
      if (cmp(a1,pi) > 0)	 a1 -= 2*pi;
      if (cmp(a0,a1) > 0) {
        e[tote++] = Event(a0,1);
        e[tote++] = Event(pi,-1);
        e[tote++] = Event(-pi,1);
        e[tote++] = Event(a1,-1);
      } else {
        e[tote++] = Event(a0,1);
        e[tote++] = Event(a1,-1);
      }
    }
  sort(e,e+tote,Eventcmp);
  cur = 0;
  for (int j = 0; j < tote; j++) {
    if (cur != 0 && cmp(e[j].tim,pre[cur]) != 0) {
      ans[cur] += Area(e[j].tim-pre[cur],c[i].r);
      ans[cur] += xmult(Point(c[i].c.x+c[i].r*cos(pre[cur]),c[i].c.y+c[i].r*sin(pre[cur])),
                        Point(c[i].c.x+c[i].r*cos(e[j].tim),c[i].c.y+c[i].r*sin(e[j].tim)))/2.0;
    }
    cur += e[j].typ;
    pre[cur] = e[j].tim;
  }
}
for (int i = 1; i < n; i++)
  ans[i] -= ans[i+1];
