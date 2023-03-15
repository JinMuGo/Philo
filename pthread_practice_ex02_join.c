/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_practice_ex02_join.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:38 by jgo               #+#    #+#             */
/*   Updated: 2023/03/15 19:58:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void *arg) {
    int *value = (int *) arg;
    printf("Thread function started with argument %d\n", *value);
    sleep(3);
    *value = 20;
    printf("Thread function finished\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    int value = 10;

    if (pthread_create(&tid, NULL, thread_function, &value)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    printf("Main function started\n");

    if (pthread_join(tid, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    printf("Value changed by thread: %d\n", value);
    printf("Main function finished\n");
    pthread_exit(NULL);
}