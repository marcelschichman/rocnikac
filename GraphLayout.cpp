#include "GraphLayout.h"
//#include "point.h"

void GraphLayout::export_to_svg(char * filename) {
    
    int width = 300, height = 300;
    int offset = 20;
    
    normalize(width, height, offset);
    
    init_svg(filename);
    
    for (int i = 0; i < graph->size(); i++) {
        for (int j = 0; j < graph->size(); j++) {
            if (graph->connected(i, j)) {
                draw_arrow(pos[i], pos[j]);
            }
        }
    }
    
    for (auto p : pos) {
        draw_circle(p);
    }
    
    finalize_svg();
}

void GraphLayout::normalize(int width, int height, int offset) {
    if (pos.size()==0)
        return;
    
    double min_x = pos[0].x, max_x = pos[0].x;
    double min_y = pos[0].y, max_y = pos[0].y;
    for (Point p : pos) {
        min_x = min(min_x, p.x);
        max_x = max(max_x, p.x);
        min_y = min(min_y, p.y);
        max_y = max(max_y, p.y);
    }
    double scale_x = (width - 2*offset) / (max_x - min_x);
    double scale_y = (height - 2*offset) / (max_y - min_y);
        
    for (int i = 0; i < pos.size(); i++) {
        pos[i].x = (pos[i].x - min_x) * scale_x + offset;
        pos[i].y = (pos[i].y - min_y) * scale_y + offset;
    }
}

void GraphLayout::init_svg(char * filename) {
    f = fopen(filename, "w");
    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"300\" width=\"300\" version=\"1.1\">\n\r");
}

void GraphLayout::finalize_svg() {
    fprintf(f, "</svg>");
    fclose(f);
}

void GraphLayout::draw_circle(Point & s) {
    fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"4\" stroke=\"black\" stroke-width=\"1\" fill=\"red\" />\n\r", (int)(s.x), (int)(s.y));
}

void GraphLayout::draw_arrow(Point & a, Point & b) {
    double arrow_width = 5;
    double arrow_length = 14;
    double arrow_offset = 4;
    
    Point vector = (b - a) * (1 / abs(b - a));
    Point norm = {vector.y, -vector.x};
    Point arrow1 = ((-arrow_length) * vector) + (norm * arrow_width);
    Point arrow2 = ((-arrow_length) * vector) - (norm * arrow_width);
    Point offset = (-arrow_offset) * vector;
    
    fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:black;stroke-width:1\" />\n\r", (int)(a.x), (int)(a.y), (int)(b.x), (int)(b.y));
    fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:black;stroke-width:1\" />\n\r", 
            (int)(b.x + offset.x), (int)(b.y + offset.y), (int)(b.x + arrow1.x), (int)(b.y + arrow1.y));
    fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:black;stroke-width:1\" />\n\r", 
            (int)(b.x + offset.x), (int)(b.y + offset.y), (int)(b.x + arrow2.x), (int)(b.y + arrow2.y));
}
