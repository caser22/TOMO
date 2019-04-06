double PartialDifferential(double v1, double v2, double v3, double v4, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x, int y)
{
	double c1, c2, c3, c4, c5, c6, c7, c1v1, c1v2, c1d3, c1v4, c2v1, c2v2, c2v3, c2v4, c3v1, c3v2, c3v3, c3v4, c4v1, c4v2, c4v3, c4v4, c5v1, c5v2, c5v3, c5v4;
	double s1, s2, b1, b2;
	double V, vc1, vc2, vc3, vc4, vc5, vv1, vv2, vv3, vv4;
	double c6c7;
	s1 = (y1 - y2) / (x1 - x2);
	s2 = (y3 - y4) / (x3 - x4);
	b1 = y1 - s1*x1;
	b2 = y3 - s2*x3;
	c1 = s2*(x2*v1 - x1*v2) + b2*(v2 - v1) - s1*(x2*v3 - x1*v4) - b1*(v4 - v3);
	c2 = s2*(v2 - v1) - s1*(v4 - v3);
	c3 = x1*v2 - x2*v1 + x2*v3 - x1*v4;
	c4 = v1 - v2 + v4 - v3;
	c5 = b2*(x2*v1 - x1*v2) - b1*(x2*v3 - x1*v4);
	c6 = (s2 - s1)*(x2 - x1);
	c7 = (b2 - b1)*(x2 - x1);
	c6c7 = c6*x + c7;
	//--------------------------------c1偏微分
	c1v1 = s2*x2 - b2;
	c1v2 = -s2*x1 + b2;
	c1v3 = -s1*x2 + b1;
	c1v4 = s1*x1 - b1;
	//--------------------------------c2偏微分
	c2v1 = -s2;
	c2v2 = s2;
	c2v3 = s1;
	c2v4 = -s1;
	//--------------------------------c3偏微分
	c3v1 = -x2;
	c3v2 = x1;
	c3v3 = x2;
	c3v4 = -x1;
	//--------------------------------c4偏微分
	c4v1 = 1;
	c4v2 = -1;
	c4v3 = -1;
	c4v4 = 1;
	//--------------------------------c5偏微分
	c5v1 = b2*x2;
	c5v2 = -b2*x1;
	c5v3 = -b1*x2;
	c5v4 = b1*x1;
	//--------------------------------v偏微分(对c)
	vc1 = x / c6c7;
	vc2 = pow(x, 2) / c6c7;
	vc3 = y / c6c7;
	vc4 = (x*z) / c6c7;
	vc5 = 1 / c6c7;
	//--------------------------------v偏微分(链式法则)
	vv1 = vc1*c1v1 + vc2*c2v1 + vc3*c3v1 + vc4*c4v1 + vc5*c5v1;
	vv2 = vc1*c1v2 + vc2*c2v2 + vc3*c3v2 + vc4*c4v2 + vc5*c5v2;
	vv3 = vc1*c1v3 + vc2*c2v3 + vc3*c3v3 + vc4*c4v3 + vc5*c5v3;
	vv4 = vc1*c1v4 + vc2*c2v4 + vc3*c3v4 + vc4*c4v4 + vc5*c5v4;
}