#include <iostream>
using namespace std;
//ÈýÎ¬¼¸ºÎº¯Êý¿â
#include <cmath>

const double EPS = 1e-8;

struct Point3D {
	double x, y, z;
};

struct Line3D {
	Point3D a, b;
};

struct Plane {
	Point3D a, b, c;
};

struct PlaneF {
	// ax + by + cz + d = 0
	double a, b, c, d;
};

inline bool zero(double x) {
	return (x > 0 ? x : -x) < EPS;
}

//Æ½·½
inline double sqr(double d) {
	return d * d;
}

//¼ÆËãcross product U x V
inline Point3D xmult(const Point3D & u, const Point3D & v) {
	Point3D ret;
	ret.x = u.y * v.z - v.y * u.z;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return ret;
}

//¼ÆËãdot product U . V
inline double dmult(const Point3D & u, const Point3D & v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

//Ê¸Á¿²î U - V
inline Point3D subt(const Point3D & u, const Point3D & v) {
	Point3D ret;
	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	ret.z = u.z - v.z;
	return ret;
}

//È¡Æ½Ãæ·¨ÏòÁ¿
inline Point3D pvec(const Plane & s) {
	return xmult(subt(s.a, s.b), subt(s.b, s.c));
}
inline Point3D pvec(const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return xmult(subt(s1, s2), subt(s2, s3));
}
inline Point3D pvec(const PlaneF & p) {
	Point3D ret;
	ret.x = p.a;
	ret.y = p.b;
	ret.z = p.c;
	return ret;
}

//Á½µã¾àÀë
inline double dis(const Point3D & p1, const Point3D & p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}

//ÏòÁ¿´óÐ¡
inline double vlen(const Point3D & p) {
	return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

//ÏòÁ¿´óÐ¡µÄÆ½·½
inline double sqrlen(const Point3D & p) {
	return (p.x*p.x + p.y*p.y + p.z*p.z);
}

//ÅÐÈýµã¹²Ïß
bool dotsInline(const Point3D & p1, const Point3D & p2, const Point3D & p3) {
	return sqrlen(xmult(subt(p1, p2), subt(p2, p3))) < EPS;
}

//ÅÐËÄµã¹²Ãæ
bool dotsOnplane(const Point3D & a, const Point3D & b, const Point3D & c, const Point3D & d) {
	return zero(dmult(pvec(a, b, c), subt(d, a)));
}

//ÅÐµãÊÇ·ñÔÚÏß¶ÎÉÏ, °üÀ¨¶ËµãºÍ¹²Ïß
bool dotOnlineIn(const Point3D & p, const Line3D & l) {
	return zero(sqrlen(xmult(subt(p, l.a), subt(p, l.b)))) && (l.a.x - p.x) * (l.b.x - p.x) < EPS && (l.a.y - p.y) * (l.b.y - p.y) < EPS && (l.a.z - p.z) * (l.b.z - p.z) < EPS;
}
bool dotOnlineIn(const Point3D & p, const Point3D & l1, const Point3D & l2) {
	return zero(sqrlen(xmult(subt(p, l1), subt(p, l2)))) && (l1.x - p.x) * (l2.x - p.x) < EPS && (l1.y - p.y) * (l2.y - p.y) < EPS && (l1.z - p.z) * (l2.z - p.z) < EPS;
}

//ÅÐµãÊÇ·ñÔÚÏß¶ÎÉÏ, ²»°üÀ¨¶Ëµã
bool dotOnlineEx(const Point3D & p, const Line3D & l) {
	return dotOnlineIn(p, l) && (!zero(p.x - l.a.x) || !zero(p.y - l.a.y) || !zero(p.z - l.a.z)) && (!zero(p.x - l.b.x) || !zero(p.y - l.b.y) || !zero(p.z - l.b.z));
}
bool dotOnlineEx(const Point3D & p, const Point3D & l1, const Point3D & l2) {
	return dotOnlineIn(p, l1, l2) && (!zero(p.x - l1.x) || !zero(p.y - l1.y) || !zero(p.z - l1.z)) && (!zero(p.x - l2.x) || !zero(p.y - l2.y) || !zero(p.z - l2.z));
}

//ÅÐµãÊÇ·ñÔÚ¿Õ¼äÈý½ÇÐÎÉÏ, °üÀ¨±ß½ç, Èýµã¹²ÏßÎÞÒâÒå
bool dotInplaneIn(const Point3D & p, const Plane & s) {
	return zero(vlen(xmult(subt(s.a, s.b), subt(s.a, s.c))) - vlen(xmult(subt(p, s.a), subt(p, s.b))) - vlen(xmult(subt(p, s.b), subt(p, s.c))) - vlen(xmult(subt(p, s.c), subt(p, s.a))));
}
bool dotInplaneIn(const Point3D & p, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return zero(vlen(xmult(subt(s1, s2), subt(s1, s3))) - vlen(xmult(subt(p, s1), subt(p, s2))) - vlen(xmult(subt(p, s2), subt(p, s3))) - vlen(xmult(subt(p, s3), subt(p, s1))));
}

//ÅÐµãÊÇ·ñÔÚ¿Õ¼äÈý½ÇÐÎÉÏ, ²»°üÀ¨±ß½ç, Èýµã¹²ÏßÎÞÒâÒå
bool dotInplaneEx(const Point3D & p, const Plane & s) {
	return dotInplaneIn(p, s) && sqrlen(xmult(subt(p, s.a), subt(p, s.b))) > EPS && sqrlen(xmult(subt(p, s.b), subt(p, s.c))) > EPS && sqrlen(xmult(subt(p, s.c), subt(p, s.a))) > EPS;
}
bool dotInplaneEx(const Point3D & p, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return dotInplaneIn(p, s1, s2, s3) && sqrlen(xmult(subt(p, s1), subt(p, s2))) > EPS && sqrlen(xmult(subt(p, s2), subt(p, s3))) > EPS && sqrlen(xmult(subt(p, s3), subt(p, s1))) > EPS;
}

//ÅÐÁ½µãÔÚÏß¶ÎÍ¬²à, µãÔÚÏß¶ÎÉÏ·µ»Ø0, ²»¹²ÃæÎÞÒâÒå
bool sameSide(const Point3D & p1, const Point3D & p2, const Line3D & l) {
	return dmult(xmult(subt(l.a, l.b), subt(p1, l.b)), xmult(subt(l.a, l.b), subt(p2, l.b))) > EPS;
}
bool sameSide(const Point3D & p1, const Point3D & p2, const Point3D & l1, const Point3D & l2) {
	return dmult(xmult(subt(l1, l2), subt(p1, l2)), xmult(subt(l1, l2), subt(p2, l2))) > EPS;
}

//ÅÐÁ½µãÔÚÏß¶ÎÒì²à, µãÔÚÏß¶ÎÉÏ·µ»Ø0, ²»¹²ÃæÎÞÒâÒå
bool oppositeSide(const Point3D & p1, const Point3D & p2, const Line3D & l) {
	return dmult(xmult(subt(l.a, l.b), subt(p1, l.b)), xmult(subt(l.a, l.b), subt(p2, l.b))) < -EPS;
}
bool oppositeSide(const Point3D & p1, const Point3D & p2, const Point3D & l1, const Point3D & l2) {
	return dmult(xmult(subt(l1, l2), subt(p1, l2)), xmult(subt(l1, l2), subt(p2, l2))) < -EPS;
}

//ÅÐÁ½µãÔÚÆ½ÃæÍ¬²à, µãÔÚÆ½ÃæÉÏ·µ»Ø0
bool sameSide(const Point3D & p1, const Point3D & p2, const Plane & s) {
	return dmult(pvec(s), subt(p1, s.a)) * dmult(pvec(s), subt(p2, s.a)) > EPS;
}
bool sameSide(const Point3D & p1, const Point3D & p2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return dmult(pvec(s1, s2, s3), subt(p1, s1)) * dmult(pvec(s1, s2, s3), subt(p2, s1)) > EPS;
}
bool sameSide(const Point3D & p1, const Point3D & p2, const PlaneF & s) {
	return (s.a * p1.x + s.b * p1.y + s.c * p1.z + s.d) * (s.a * p2.x + s.b * p2.y + s.c * p2.z + s.d) > EPS;
}

//ÅÐÁ½µãÔÚÆ½ÃæÒì²à, µãÔÚÆ½ÃæÉÏ·µ»Ø0
bool oppositeSide(const Point3D & p1, const Point3D & p2, const Plane & s) {
	return dmult(pvec(s), subt(p1, s.a)) * dmult(pvec(s), subt(p2, s.a)) < -EPS;
}
bool oppositeSide(const Point3D & p1, const Point3D & p2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return dmult(pvec(s1, s2, s3), subt(p1, s1)) * dmult(pvec(s1, s2, s3), subt(p2, s1)) < -EPS;
}
bool oppositeSide(const Point3D & p1, const Point3D & p2, const PlaneF & s) {
	return (s.a*p1.x+s.b*p1.y+s.c*p1.z+s.d) * (s.a*p2.x+s.b*p2.y+s.c*p2.z+s.d) < -EPS;
}

//ÅÐÁ½Ö±ÏßÆ½ÐÐ
bool parallel(const Line3D & u, const Line3D & v) {
	return sqrlen(xmult(subt(u.a, u.b), subt(v.a, v.b))) < EPS;
}
bool parallel(const Point3D & u1, const Point3D & u2, const Point3D & v1, const Point3D & v2) {
	return sqrlen(xmult(subt(u1, u2), subt(v1, v2))) < EPS;
}

//ÅÐÁ½Æ½ÃæÆ½ÐÐ
bool parallel(const Plane & u, const Plane & v) {
	return sqrlen(xmult(pvec(u), pvec(v))) < EPS;
}
bool parallel(const Point3D & u1, const Point3D & u2, const Point3D & u3, const Point3D & v1, const Point3D & v2, const Point3D & v3) {
	return sqrlen(xmult(pvec(u1, u2, u3), pvec(v1, v2, v3))) < EPS;
}
bool parallel(const PlaneF & u, const PlaneF & v) {
	return sqrlen(xmult(pvec(u), pvec(v))) < EPS;
}

//ÅÐÖ±ÏßÓëÆ½ÃæÆ½ÐÐ
bool parallel(const Line3D & l, const Plane & s) {
	return zero(dmult(subt(l.a, l.b), pvec(s)));
}
bool parallel(const Point3D & l1, const Point3D & l2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return zero(dmult(subt(l1, l2), pvec(s1, s2, s3)));
}
bool parallel(const Line3D & l, const PlaneF & s) {
	return zero(dmult(subt(l.a, l.b), pvec(s)));
}

//ÅÐÁ½Ö±Ïß´¹Ö±
bool perpendicular(const Line3D & u, const Line3D & v) {
	return zero(dmult(subt(u.a, u.b), subt(v.a, v.b)));
}
bool perpendicular(const Point3D & u1, const Point3D & u2, const Point3D & v1, const Point3D & v2) {
	return zero(dmult(subt(u1, u2), subt(v1, v2)));
}

//ÅÐÁ½Æ½Ãæ´¹Ö±
bool perpendicular(const Plane & u, const Plane & v) {
	return zero(dmult(pvec(u), pvec(v)));
}
bool perpendicular(const Point3D & u1, const Point3D & u2, const Point3D & u3, const Point3D & v1, const Point3D & v2, const Point3D & v3) {
	return zero(dmult(pvec(u1, u2, u3), pvec(v1, v2, v3)));
}
bool perpendicular(const PlaneF & u, const PlaneF & v) {
	return zero(dmult(pvec(u), pvec(v)));
}

//ÅÐÖ±ÏßÓëÆ½Ãæ´¹Ö±
bool perpendicular(const Line3D & l, const Plane & s) {
	return sqrlen(xmult(subt(l.a, l.b), pvec(s))) < EPS;
}
bool perpendicular(const Point3D & l1, const Point3D & l2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return sqrlen(xmult(subt(l1, l2), pvec(s1, s2, s3))) < EPS;
}
bool perpendicular(const Line3D & l, const PlaneF & s) {
	return sqrlen(xmult(subt(l.a, l.b), pvec(s))) < EPS;
}

//ÅÐÁ½Ïß¶ÎÏà½», °üÀ¨¶ËµãºÍ²¿·ÖÖØºÏ
bool intersectIn(const Line3D & u, const Line3D & v) {
	if (!dotsOnplane(u.a, u.b, v.a, v.b)) {
		return 0;
	} else if (!dotsInline(u.a, u.b, v.a) || !dotsInline(u.a, u.b, v.b)) {
		return !sameSide(u.a, u.b, v) && !sameSide(v.a, v.b, u);
	} else {
		return dotOnlineIn(u.a, v) || dotOnlineIn(u.b, v) || dotOnlineIn(v.a, u) || dotOnlineIn(v.b, u);
	}
}
bool intersectIn(const Point3D & u1, const Point3D & u2, const Point3D & v1, const Point3D & v2) {
	if (!dotsOnplane(u1, u2, v1, v2)) {
		return 0;
	} else if (!dotsInline(u1, u2, v1) || !dotsInline(u1, u2, v2)) {
		return !sameSide(u1, u2, v1, v2) && !sameSide(v1, v2, u1, u2);
	} else {
		return dotOnlineIn(u1, v1, v2) || dotOnlineIn(u2, v1, v2) || dotOnlineIn(v1, u1, u2) || dotOnlineIn(v2, u1, u2);
	}
}

//ÅÐÁ½Ïß¶ÎÏà½», ²»°üÀ¨¶ËµãºÍ²¿·ÖÖØºÏ
bool intersectEx(const Line3D & u, const Line3D & v) {
	return dotsOnplane(u.a, u.b, v.a, v.b) && oppositeSide(u.a, u.b, v) && oppositeSide(v.a, v.b, u);
}
bool intersectEx(const Point3D & u1, const Point3D & u2, const Point3D & v1, const Point3D & v2) {
	return dotsOnplane(u1, u2, v1, v2) && oppositeSide(u1, u2, v1, v2) && oppositeSide(v1, v2, u1, u2);
}

//ÅÐÏß¶ÎÓë¿Õ¼äÈý½ÇÐÎÏà½», °üÀ¨½»ÓÚ±ß½çºÍ(²¿·Ö)°üº¬
bool intersectIn(const Line3D & l, const Plane & s) {
	return !sameSide(l.a, l.b, s) && !sameSide(s.a, s.b, l.a, l.b, s.c) && !sameSide(s.b, s.c, l.a, l.b, s.a) && !sameSide(s.c, s.a, l.a, l.b, s.b);
}
bool intersectIn(const Point3D & l1, const Point3D & l2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return !sameSide(l1, l2, s1, s2, s3) && !sameSide(s1, s2, l1, l2, s3) && !sameSide(s2, s3, l1, l2, s1) && !sameSide(s3, s1, l1, l2, s2);
}

//ÅÐÏß¶ÎÓë¿Õ¼äÈý½ÇÐÎÏà½», ²»°üÀ¨½»ÓÚ±ß½çºÍ(²¿·Ö)°üº¬
bool intersectEx(const Line3D & l, const Plane & s) {
	return oppositeSide(l.a, l.b, s) && oppositeSide(s.a, s.b, l.a, l.b, s.c) && oppositeSide(s.b, s.c, l.a, l.b, s.a) && oppositeSide(s.c, s.a, l.a, l.b, s.b);
}
bool intersectEx(const Point3D & l1, const Point3D & l2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return oppositeSide(l1, l2, s1, s2, s3) && oppositeSide(s1, s2, l1, l2, s3) && oppositeSide(s2, s3, l1, l2, s1) && oppositeSide(s3, s1, l1, l2, s2);
}

//¼ÆËãÁ½Ö±Ïß½»µã, ×¢ÒâÊÂÏÈÅÐ¶ÏÖ±ÏßÊÇ·ñ¹²ÃæºÍÆ½ÐÐ!
//Ïß¶Î½»µãÇëÁíÍâÅÐÏß¶ÎÏà½»(Í¬Ê±»¹ÊÇÒªÅÐ¶ÏÊÇ·ñÆ½ÐÐ!)
#include <algorithm>

using namespace std;
/*
Point3D intersection(Line3D u, Line3D v) {
	if (zero(u.a.x - u.b.x) && zero(v.a.x - v.b.x)) {
		swap(u.a.x, u.a.z);
		swap(u.b.x, u.b.z);
		swap(v.a.x, v.a.z);
		swap(v.b.x, v.b.z);
		Point3D ret = intersection(u, v);
		swap(ret.x, ret.z);
		return ret;
	} else if (zero(u.a.y - u.b.y) && zero(v.a.y - v.b.y)) {
		swap(u.a.y, u.a.z);
		swap(u.b.y, u.b.z);
		swap(v.a.y, v.a.z);
		swap(v.b.y, v.b.z);
		Point3D ret = intersection(u, v);
		swap(ret.y, ret.z);
		return ret;
	} else {
		Point3D ret = u.a; 
		double t = ((u.a.x - v.a.x) * (v.a.y - v.b.y) - (u.a.y - v.a.y) * (v.a.x - v.b.x)) / ((u.a.x - u.b.x) * (v.a.y - v.b.y) - (u.a.y - u.b.y) * (v.a.x - v.b.x));
		ret.x += (u.b.x - u.a.x) * t; 
		ret.y += (u.b.y - u.a.y) * t; 
		ret.z += (u.b.z - u.a.z) * t; 
		return ret; 
	}
}*/
Point3D intersection(Point3D u1, Point3D u2, Point3D v1, Point3D v2) {
   double dxu = u2.x - u1.x;
   double dyu = u2.y - u1.y;
   double dzu = u2.z - u1.z;
   double dxv = v2.x - v1.x;
   double dyv = v2.y - v1.y;
   double dzv = v2.z - v1.z;
   double t;
   if (!zero(dxu * dyv - dyu * dxv)) {
      t = (dyv * (v1.x - u1.x) + dxv * (u1.y - v1.y)) / (dxu * dyv - dyu * dxv);
   } else if (!zero(dxu * dzv - dzu * dxv)) {
      t = (dzv * (v1.x - u1.x) + dxv * (u1.z - v1.z)) / (dxu * dzv - dzu * dxv);
   } else {
      t = (dzv * (v1.y - u1.y) + dyv * (u1.z - v1.z)) / (dyu * dzv - dzu * dyv);
   }
   Point3D ret;
   ret.x = u1.x + dxu * t;
   ret.y = u1.y + dyu * t;
   ret.z = u1.z + dzu * t;
   return ret;
}

//¼ÆËãÖ±ÏßÓëÆ½Ãæ½»µã, ×¢ÒâÊÂÏÈÅÐ¶ÏÊÇ·ñÆ½ÐÐ, ²¢±£Ö¤Èýµã²»¹²Ïß!
//Ïß¶ÎºÍ¿Õ¼äÈý½ÇÐÎ½»µãÇëÁíÍâÅÐ¶Ï
Point3D intersection(const Line3D & l, const Plane & s) {
	Point3D ret = pvec(s);
	double t = (ret.x * (s.a.x - l.a.x) + ret.y * (s.a.y - l.a.y) + ret.z * (s.a.z - l.a.z)) / (ret.x * (l.b.x - l.a.x) + ret.y * (l.b.y - l.a.y) + ret.z * (l.b.z - l.a.z));
	ret.x = l.a.x + (l.b.x - l.a.x) * t;
	ret.y = l.a.y + (l.b.y - l.a.y) * t;
	ret.z = l.a.z + (l.b.z - l.a.z) * t;
	return ret;
}
Point3D intersection(const Point3D & l1, const Point3D & l2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	Point3D ret = pvec(s1, s2, s3);
	double t = (ret.x * (s1.x - l1.x) + ret.y * (s1.y - l1.y) + ret.z * (s1.z - l1.z)) / (ret.x * (l2.x - l1.x) + ret.y * (l2.y - l1.y) + ret.z * (l2.z - l1.z));
	ret.x = l1.x + (l2.x - l1.x) * t;
	ret.y = l1.y + (l2.y - l1.y) * t;
	ret.z = l1.z + (l2.z - l1.z) * t;
	return ret;
}
Point3D intersection(const Line3D & l, const PlaneF & s) {
	Point3D ret = subt(l.b, l.a);
	double t = -(dmult(pvec(s), l.a) + s.d) / (dmult(pvec(s), ret));
	ret.x = ret.x * t + l.a.x;
	ret.y = ret.y * t + l.a.y;
	ret.z = ret.z * t + l.a.z;
	return ret;
}

//¼ÆËãÁ½Æ½Ãæ½»Ïß, ×¢ÒâÊÂÏÈÅÐ¶ÏÊÇ·ñÆ½ÐÐ, ²¢±£Ö¤Èýµã²»¹²Ïß!
Line3D intersection(const Plane & u, const Plane & v) {
	Line3D ret;
	ret.a = parallel(v.a, v.b, u.a, u.b, u.c) ? intersection(v.b, v.c, u.a, u.b, u.c) : intersection(v.a, v.b, u.a, u.b, u.c);
	ret.b = parallel(v.c, v.a, u.a, u.b, u.c) ? intersection(v.b, v.c, u.a, u.b, u.c) : intersection(v.c, v.a, u.a, u.b, u.c);
	return ret;
}
Line3D intersection(const Point3D & u1, const Point3D & u2, const Point3D & u3, const Point3D & v1, const Point3D & v2, const Point3D & v3) {
	Line3D ret;
	ret.a = parallel(v1, v2, u1, u2, u3) ? intersection(v2, v3, u1, u2, u3) : intersection(v1, v2, u1, u2, u3);
	ret.b = parallel(v3, v1, u1, u2, u3) ? intersection(v2, v3, u1, u2, u3) : intersection(v3, v1, u1, u2, u3);
	return ret;
}

//µãµ½Ö±Ïß¾àÀë
double disptoline(const Point3D & p, const Line3D & l) {
	return vlen(xmult(subt(p, l.a), subt(l.b, l.a))) / dis(l.a, l.b);
}
Point3D ptoline(const Point3D & p, const Line3D & l);
inline double sgn(double num) {
	if(fabs(num) < EPS)
		return 0;
	else if(num < 0)
		return -1.0;
	else if(num > 0)
		return 1.0;
}
#include <cstdio>
double disptoline(const Point3D & p, const Point3D & l1, const Point3D & l2) {
	Line3D l;
	l.a = l1;
	l.b = l2;
	Point3D t = ptoline(p, l);
	//printf("%lf %lf %lf\n", t.x, t.y, t.z);
	if(sgn(l2.x - l1.x) * sgn(t.x - l1.x) >= 0
	&& sgn(l2.y - l1.y) * sgn(t.y - l1.y) >= 0
	&& sgn(l2.z - l1.z) * sgn(t.z - l1.z) >= 0)
		return vlen(xmult(subt(p, l1), subt(l2, l1))) / dis(l1, l2);
	else	
		return min(dis(l1, p), dis(l2, p));
}

//µãµ½Ö±Ïß×î½üµã
Point3D ptoline(const Point3D & p, const Line3D & l) {
	Point3D ab = subt(l.b, l.a);
	double t = - dmult(subt(p, l.a), ab) / sqrlen(ab);
	ab.x *= t;
	ab.y *= t;
	ab.z *= t;
	return subt(l.a, ab);
}

//µãµ½Æ½Ãæ¾àÀë
double disptoplane(const Point3D & p, const Plane & s) {
	return fabs(dmult(pvec(s), subt(p, s.a))) / vlen(pvec(s));
}
double disptoplane(const Point3D & p, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return fabs(dmult(pvec(s1, s2, s3), subt(p, s1))) / vlen(pvec(s1, s2, s3));
}
double disptoplane(const Point3D & p, const PlaneF & s) {
	return fabs((dmult(pvec(s), p)+s.d) / vlen(pvec(s)));
}

//µãµ½Æ½Ãæ×î½üµã
Point3D ptoplane(const Point3D & p, const PlaneF & s) {
	Line3D l;
	l.a = p;
	l.b = pvec(s);
	l.b.x += p.x;
	l.b.y += p.y;
	l.b.z += p.z;
	return intersection(l, s);
}

//Ö±Ïßµ½Ö±Ïß¾àÀë
double dislinetoline(const Line3D & u, const Line3D & v) {
	Point3D n = xmult(subt(u.a, u.b), subt(v.a, v.b));
	return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}
double dislinetoline(const Point3D & u1, const Point3D & u2, const Point3D & v1, const Point3D & v2) {
	Point3D n = xmult(subt(u1, u2), subt(v1, v2));
	return fabs(dmult(subt(u1, v1), n)) / vlen(n);
}

//Ö±Ïßµ½Ö±ÏßµÄ×î½üµã¶Ô
//p1ÔÚuÉÏ£¬p2ÔÚvÉÏ£¬p1µ½p2ÊÇuvÖ®¼äµÄ×î½ü¾àÀë
//×¢Òâ£¬±£Ö¤Á½Ö±Ïß²»Æ½ÐÐ
void linetoline(const Line3D & u, const Line3D & v, Point3D &p1, Point3D &p2) {
	Point3D ab = subt(u.b, u.a), cd = subt(v.b, v.a), ac = subt(v.a, u.a);
	double r = (dmult(ab, cd) * dmult(ac, ab) - sqrlen(ab) * dmult(ac, cd)) / (sqrlen(ab)*sqrlen(cd) - sqr(dmult(ab, cd)));
	p2.x = v.a.x + r * cd.x;
	p2.y = v.a.y + r * cd.y;
	p2.z = v.a.z + r * cd.z;
	p1 = ptoline(p2, u);
}

//Á½Ö±Ïß¼Ð½ÇcosÖµ
double angleCos(const Line3D & u, const Line3D & v) {
	return dmult(subt(u.a, u.b), subt(v.a, v.b)) / vlen(subt(u.a, u.b)) / vlen(subt(v.a, v.b));
}
double angleCos(const Point3D & u1, const Point3D & u2, const Point3D & v1, const Point3D & v2) {
	return dmult(subt(u1, u2), subt(v1, v2)) / vlen(subt(u1, u2)) / vlen(subt(v1, v2));
}

//Á½Æ½Ãæ¼Ð½ÇcosÖµ
double angleCos(const Plane & u, const Plane & v) {
	return dmult(pvec(u), pvec(v)) / vlen(pvec(u)) / vlen(pvec(v));
}
double angleCos(const Point3D & u1, const Point3D & u2, const Point3D & u3, const Point3D & v1, const Point3D & v2, const Point3D & v3) {
	return dmult(pvec(u1, u2, u3), pvec(v1, v2, v3)) / vlen(pvec(u1, u2, u3)) / vlen(pvec(v1, v2, v3));
}
double angleCos(const PlaneF & u, const PlaneF & v) {
	return dmult(pvec(u), pvec(v)) / (vlen(pvec(u)) * vlen(pvec(v)));
}

//Ö±ÏßÆ½Ãæ¼Ð½ÇsinÖµ
double angleSin(const Line3D & l, const Plane & s) {
	return dmult(subt(l.a, l.b), pvec(s)) / vlen(subt(l.a, l.b)) / vlen(pvec(s));
}
double angleSin(const Point3D & l1, const Point3D & l2, const Point3D & s1, const Point3D & s2, const Point3D & s3) {
	return dmult(subt(l1, l2), pvec(s1, s2, s3)) / vlen(subt(l1, l2)) / vlen(pvec(s1, s2, s3));
}
double angleSin(Line3D l, const PlaneF & s) {
	return dmult(subt(l.a, l.b), pvec(s)) / (vlen(subt(l.a, l.b)) * vlen(pvec(s)));
}

// Æ½Ãæ·½³ÌÐÎÊ½×ª»¯ Plane -> PlaneF
PlaneF planeToPlaneF(const Plane & p) {
	PlaneF ret;
	Point3D m = xmult(subt(p.b, p.a), subt(p.c, p.a));
	ret.a = m.x;
	ret.b = m.y;
	ret.c = m.z;
	ret.d = -m.x * p.a.x - m.y * p.a.y - m.z * p.a.z;
	return ret;
}
#include <cstdio>
int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		Point3D l1, l2;
		scanf("%lf%lf%lf", &l1.x, &l1.y, &l1.z);
		scanf("%lf%lf%lf", &l2.x, &l2.y, &l2.z);
		double maxlen = 0;
		for(int i = 0; i < N; ++i) {
			Point3D p;
			scanf("%lf%lf%lf", &p.x, &p.y, &p.z);
			double thislen = disptoline(p, l1, l2);
			if(thislen > maxlen)
				maxlen = thislen;
		}
		printf("%.2lf\n", maxlen);
	}
	return 0;
}
