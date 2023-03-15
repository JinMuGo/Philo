/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_practice_ex03_mutex.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:08:07 by jgo               #+#    #+#             */
/*   Updated: 2023/03/15 20:09:21 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;  // 뮤텍스 변수 선언
int count = 0;

void *increment(void *arg) {
    int i;
    for (i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex);  // 뮤텍스 락
        count++;
        pthread_mutex_unlock(&mutex);  // 뮤텍스 언락
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int i;

    // 뮤텍스 초기화
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("mutex init error\n");
        return 1;
    }

    // 스레드 생성
    for (i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, increment, NULL) != 0) {
            printf("thread create error\n");
            return 1;
        }
    }

    // 스레드 종료 대기
    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("thread join error\n");
            return 1;
        }
    }

    // 뮤텍스 삭제
    pthread_mutex_destroy(&mutex);

    printf("count: %d\n", count);
    return 0;
}