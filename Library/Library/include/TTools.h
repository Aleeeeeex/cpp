#ifndef TTOOLS_H
#define TTOOLS_H
#define GETTAG(line, tag, tagContent) {                     \
    int tagStart, tagEnd, ctagStart;                        \
    tagStart = line.find("<", 0) + 1;                       \
    tagEnd = line.find(">", tagStart);                      \
                                                            \
    ctagStart = line.find("</", tagEnd);                    \
                                                            \
    tag = line.substr(tagStart, (tagEnd - tagStart));       \
    tagContent = line.substr(tagEnd+1, ctagStart-tagEnd-1); \
}
#endif
