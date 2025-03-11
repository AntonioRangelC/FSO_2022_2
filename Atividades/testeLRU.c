#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGE_FRAMES 1000000
#define MAX_PAGE_REQUESTS 10000000

struct Page {
    int page_number;
    int last_used_time;
};

int main(){
    int num_page_frames;
    int hits = 0;

    scanf("%d", &num_page_frames);

    int num_page_requests;

    scanf("%d", &num_page_requests);

    struct Page page_frames[MAX_PAGE_FRAMES];
    for (int i = 0; i < num_page_frames; i++) {
        page_frames[i].page_number = -1;
        page_frames[i].last_used_time = -1;
    }

    for (int i = 0; i < num_page_requests; i++) {
        int page_request;
        scanf("%d", &page_request);

        // Check if page is already in memory
        int page_in_memory = 0;
        for (int j = 0; j < num_page_frames; j++) {
            if (page_frames[j].page_number == page_request) {
                page_in_memory = 1;
                page_frames[j].last_used_time = i;
                hits++;
                break;
            }
        }

        // If page is not in memory, replace page using LRU strategy
        if (!page_in_memory) {
            int lru_page_frame_index = 0;
            int lru_page_frame_time = page_frames[0].last_used_time;
            for (int j = 1; j < num_page_frames; j++) {
                if (page_frames[j].last_used_time < lru_page_frame_time) {
                    lru_page_frame_index = j;
                    lru_page_frame_time = page_frames[j].last_used_time;
                }
            }
            page_frames[lru_page_frame_index].page_number = page_request;
            page_frames[lru_page_frame_index].last_used_time = i;
        }
    }

    // Count number of page faults
    int num_page_faults = num_page_requests - hits;
    if (num_page_faults < 0) {
        num_page_faults = 0;
    }
    printf("%d\n", num_page_faults);

    return 0;
}

