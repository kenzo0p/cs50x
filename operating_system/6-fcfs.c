#include <stdio.h>

int main() {
    int pages[50], frames[10], n_pages, n_frames;
    int i, j, k = 0, hit = 0, isHit;
    float hit_ratio, miss_ratio;
    printf("=== FIFO Page Replacement Algorithm ===\n");
    printf("Enter the number of pages: ");
    scanf("%d", &n_pages);
    printf("Enter the page reference string:\n");
    for (i = 0; i < n_pages; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &n_frames);
    for (i = 0; i < n_frames; i++) {
        frames[i] = -1;
    }
    printf("\nPage Replacement Process:\n");
    for (i = 0; i < n_pages; i++) {
        isHit = 0;
        for (j = 0; j < n_frames; j++) {
            if (frames[j] == pages[i]) {
                hit++;
                isHit = 1;
                break;
            }
        }
        if (isHit) {
            printf("Page %d: HIT\t\t", pages[i]);
        } else {
            frames[k] = pages[i];
            k = (k + 1) % n_frames;
            printf("Page %d: MISS\t\t", pages[i]);
        }
        for (j = 0; j < n_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    hit_ratio = (float)hit / n_pages;
    miss_ratio = 1 - hit_ratio;
    printf("\nTotal Page Hits  = %d", hit);
    printf("\nTotal Page Misses = %d", n_pages - hit);
    printf("\nHit Ratio = %.2f", hit_ratio);
    printf("\nMiss Ratio = %.2f\n", miss_ratio);
    return 0;
}

