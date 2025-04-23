#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;



typedef struct Point
    {
        int x;
        int y;
        Point() {
            this->x = 0;
            this->y = 0;
        }
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
    }Point;

struct Point result_pair[2];

bool compare_x(const Point& a, const Point& b) {
    return a.x < b.x;
}
bool compare_y(const Point& a, const Point& b) {
    return a.y < b.y;
}

double distance(Point& a, Point& b) {
    return sqrt((pow(a.x - b.x, 2)) + pow(a.y - b.y, 2));
}
double brute_force(vector <Point> points, Point* p1, Point* p2) {
    int n = points.size();
    if (n < 2) {
        p1 = NULL;
        p2 = NULL;
        return INFINITY;
    }
    double min_dist = INFINITY;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(distance(points[i], points[j]) < min_dist) {
                min_dist = distance(points[i], points[j]);
                *p1 = points[i];
                *p2 = points[j];
            }
        }
    }
    return min_dist;

}
double strip_closest(vector <Point> strip, double d, Point* p1, Point* p2) {
    double min_dist = d;
    sort(strip.begin(), strip.end(), compare_y);
    
    for(int i = 0; i < strip.size(); i++) {
        for(int j = i + 1; j < strip.size(); j++) {
            if (strip[j].y - strip[i].y >= min_dist)
                break;
            double dist = distance(strip[j], strip[i]);
            if (dist < min_dist) {
                min_dist = dist;
                *p1 = strip[i];
                *p2 = strip[j];
            }
        }
    }

    return min_dist;
}
double closest_pair(vector <Point> points, Point* p1, Point* p2) {
    int n = points.size();
    if (n <= 3) {
        return brute_force(points, p1, p2);
    }
    int mid = int(n / 2);
    vector <Point> left;
    vector <Point> right;
    
    for(int i = 0; i < mid; i++) {
        left.push_back(points[i]);
    }
    for(int i = 0; i < n-mid; i++) {
        right.push_back(points[i + mid]);
    }

    double left_dist, right_dist, strip_dist;
    Point left_p1, left_p2, right_p1, right_p2, strip_p1, strip_p2;

    left_dist = closest_pair(left, &left_p1, &left_p2);
    right_dist = closest_pair(right, &right_p1, &right_p2);
    double d;

    if(left_dist < right_dist) {
        d = left_dist;
        *p1 = left_p1;
        *p2 = left_p2;
    } else
    {
        d = right_dist;
        *p1 = right_p1;
        *p2 = right_p2;
    }
    vector <Point> strip;

    for(int i = 0; i < n; i++) {
        if (abs(points[mid].x - points[i].x) < d) {
            strip.push_back(points[i]);
        }
    }

    strip_dist = strip_closest(strip, d, &strip_p1, &strip_p2);

    if (d > strip_dist) {
        d = strip_dist;
        *p1 = strip_p1;
        *p2 = strip_p2;
    }

    return d;
}

int main(void)
{
    vector <Point> points = {
        Point(0, 2),
        Point(6, 67),
        Point(39, 107),
        Point(43, 71),
        Point(189, 140),
        
    };

    int size = points.size();
    
    sort(points.begin(), points.end(), compare_x);

    for(int i = 0; i < size; i++) {
        cout << points[i].x << ' ' << points[i].y << endl;
    }
    
    double d;
    d = closest_pair(points, &result_pair[0], &result_pair[1]);

    cout << d << endl;
    cout << result_pair[0].x << ' ' << result_pair[0].y << endl;
    cout << result_pair[1].x << ' ' << result_pair[1].y << endl;
    
    
    return 0;
}