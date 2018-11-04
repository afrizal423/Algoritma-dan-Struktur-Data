#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    // Variabel penampung data
    int data;
    // Pointer yang menunjuk ke simpul berikutnya (jika ada)
    struct node *next;
};

struct linked_list {
    // Pointer yang menunjuk ke simpul pertama
    struct node *head;
    // Pointer yang menunjuk ke simpul terakhir
    struct node *tail;
    // Jumlah simpul di dalam linked list
    int size;
};

void init(struct linked_list *ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;
}

bool is_empty(struct linked_list ll) {
    return ll.size == 0;
}

void add_first(struct linked_list *ll, int value) {
    struct node *new_node = (struct node *) malloc(sizeof(ll->head));
    new_node->data = value;
    // Simpul baru menunjuk ke simpul yang ditunjuk oleh head
    new_node->next = ll->head;
    // Memindahkan pointer head agar menunjuk ke simpul baru
    ll->head = new_node;
    // Jumlah simpul bertambah 1
    ll->size++;
    // Jika simpul baru merupakan satu-satunya simpul di dalam linked list
    if (ll->tail == NULL) {
        // Pointer tail menunjuk ke simpul baru (simpul yang ditunjukk oleh head)
        ll->tail = ll->head;
    }
}

void add_last(struct linked_list *ll, int value) {
    struct node *new_node = (struct node *) malloc(sizeof(ll->head));
    new_node->data = value;

    if (is_empty(*ll)) {
        // Head menunjuk ke simpul baru
        ll->head = new_node;
        // Tail menunjuk ke simpul yang ditunjuk oleh head
        ll->tail = ll->head;
    }
    else {
        // Menghubungkan simpul terakhir dengan simpul baru
        ll->tail->next = new_node;
        // Tail menunjuk ke simpul baru
        ll->tail = ll->tail->next;
        // Pointer tail menunjuk ke NULL
        ll->tail->next = NULL;
    }

    ll->size++;
}

int get_first(struct linked_list ll) {
    if (is_empty(ll)) {
        printf(">>> List kosong...\n");
        exit(EXIT_FAILURE);
    }
    else
        return ll.head->data;
}

int get_last(struct linked_list ll) {
    if (is_empty(ll)) {
        printf(">>> List kosong...\n");
        exit(EXIT_FAILURE);
    }
    else
        return ll.tail->data;
}

void remove_first(struct linked_list *ll) {
    if (!is_empty(*ll)) {
        struct node *temp = ll->head;
        ll->head = ll->head->next;
        ll->size--;
        free(temp);
    }
}

void remove_last(struct linked_list *ll) {
    if (!is_empty(*ll)) {
        if (ll->size == 1) {
            struct node *temp = ll->head;
            ll->head = ll->tail = NULL;
            ll->size = 0;
            free(temp);
        }
        else {
            struct node *current = ll->head;

            while (current->next != ll->tail)
                current = current->next;

            struct node *temp = ll->tail;
            ll->tail = current;
            ll->tail->next = NULL;
            ll->size--;
            free(temp);
        }
    }
}

int get_size(struct linked_list ll) {
    return ll.size;
}

void print_linked_list(struct linked_list ll) {
    struct node *current = ll.head;

    printf(">>> [");
    while (current != NULL) {
        printf("%d", current->data);
        if (current != ll.tail)
            printf(", ");

        current = current->next;
    }
    printf("]\n");
}

void contains(struct linked_list ll, int value) {
    struct node *current = ll.head;
    
    if (!is_empty(ll)) {
        while (current != NULL && current->data != value)
            current = current->next;
    }

    if (current != NULL)
        printf(">>> Data %d ada di dalam list\n", value);
    else
        printf(">>> Data %d tidak ada di dalam list\n", value);
}

int index_of(struct linked_list ll, int value) {
    int index = 0;
    struct node *current = ll.head;
    
    if (!is_empty(ll)) {
        while (current != NULL && current->data != value) {
            current = current->next;
            ++index;
        }
    }

    return current != NULL ? index : -1;
}

int get_data(struct linked_list ll, int index) {
    int count = 0;
    struct node *current = ll.head;

    if (!is_empty(ll)) {
        while (count < ll.size && count != index) {
            current = current->next;
            ++count;
        }
    }

    return current != NULL ? current->data : -1;
}

void set_data(struct linked_list *ll, int index, int value) {
    int count = 0;
    struct node *current = ll->head;

    if (!is_empty(*ll)) {
        while (count < ll->size && count != index) {
            current = current->next;
            ++count;
        }
    }

    if (current != NULL)
        current->data = value;
    else
        printf(">>> Gagal memperbarui!\n");
}

void insert(struct linked_list *ll, int index, int value) {
    int count = 0;
    struct node *current = ll->head;
    struct node *previous = NULL;

    if (!is_empty(*ll)) {
        while (current != NULL && count != index) {
            previous = current;
            current = current->next;
            ++count;
        }
    }

    if (current != NULL && index < ll->size) {
        struct node *new_node = (struct node *) malloc(sizeof(ll->head));
        new_node->data = value;

        if (index == 0) {
            // Menyisipkan node di awal
            new_node->next = ll->head;
            ll->head = new_node;
        }
        else {
            // Menyisipkan node di tengah
            new_node->next = current;
            previous->next = new_node;
        }

        ll->size++;
    }
    else
        printf(">>> Gagal menyisipkan!\n");
}

void remove_at(struct linked_list *ll, int index) {
    int count = 0;
    struct node *current = ll->head;
    struct node *previous = NULL;

    if (!is_empty(*ll)) {
        while (current != NULL && count != index) {
            previous = current;
            current = current->next;
            ++count;
        }
    }

    if (current != NULL && index < ll->size) {
        if (index == 0) {
            // Menghapus node di awal
            ll->head = current->next;
        }
        else {
            // Menghapus node di tengah/akhir
            previous->next = current->next;
            // Jika current adalah data terakhir
            if (current->next == NULL)
                ll->tail = previous;
        }

        free(current);
        ll->size--;
    }
    else
        printf(">>> Gagal menghapus!\n");
}

void clear(struct linked_list *ll) {
    struct node *current = ll->head;
    struct node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
        ll->size--;
    }

    ll->head = ll->tail = NULL;
}

void print_status(struct linked_list ll) {
    print_linked_list(ll);
    printf(">>> Nilai posisi pertama \t: %d\n", get_first(ll));
    printf(">>> Nilai posisi terakhir \t: %d\n", get_last(ll));
    printf(">>> Ukuran list \t\t: %d\n\n", get_size(ll));
}

int main() {
    struct linked_list list;
    init(&list);

    // Menambah simpul menggunakan add_first()
    add_first(&list, 20);

    // Menambah simpul menggunakan add_last()
    add_last(&list, 30);
    add_last(&list, 40);
    add_last(&list, 50);

    // Menambah simpul menggunakan add_first()
    add_first(&list, 10);

    // Menampilkan isi list
    printf("Sebelum isi list dihapus\n");
    print_status(list);

    // Mengambil isi list pada posisi pertama dan terakhir
    printf("\nMengambil isi list...\n");
    printf("Memanggil remove_first()\n");
    remove_first(&list);
    printf("Memanggil remove_last()\n");
    remove_last(&list);

    printf("\nSetelah isi list diambil\n");
    print_status(list);

    printf("Tambahan:\n");
    print_linked_list(list);
    contains(list, 40);
    printf("40 berada di indeks %d\n", index_of(list, 40));
    printf("Data pada indeks 1 adalah %d\n", get_data(list, 1));
    
    // Mengupdate data pada indeks tertentu
    printf("\nMemperbarui data pada indeks 1 dengan nilai 5...\n");
    set_data(&list, 1, 5);
    print_linked_list(list);

    // Menyisipkan data pada indeks tertentu
    printf("\nMenyisipkan 10 pada indeks 0...\n");
    insert(&list, 0, 10);
    print_linked_list(list);
    printf("Menyisipkan 15 pada indeks 1...\n");
    insert(&list, 1, 15);
    print_linked_list(list);
    printf("Menyisipkan 50 pada indeks 4...\n");
    insert(&list, 4, 50);
    print_linked_list(list);
    printf("Menyisipkan 100 pada indeks 6...\n");
    insert(&list, 6, 100);

    // Menghapus data pada indeks tertentu
    printf("\nSebelum penghapusan:\n");
    print_status(list);

    printf("Menghapus data pada indeks 0...\n");
    remove_at(&list, 0);
    print_linked_list(list);
    printf("Menghapus data pada indeks 2...\n");
    remove_at(&list, 2);
    print_linked_list(list);
    printf("Menghapus data pada indeks 3...\n");
    remove_at(&list, 3);
    print_linked_list(list);

    printf("\nSetelah penghapusan:\n");
    print_status(list);

    printf("Menghancurkan list...\n");
    clear(&list);
    print_status(list);

    return 0;
}
