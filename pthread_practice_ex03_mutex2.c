/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_practice_ex03_mutex2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:11:52 by jgo               #+#    #+#             */
/*   Updated: 2023/03/15 20:12:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1;  // 첫번째 뮤텍스
pthread_mutex_t mutex2;  // 두번째 뮤텍스

int data1 = 0;
int data2 = 0;

void *worker1(void *arg) {
    int i;
    for (i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex1);
        data1++;
        pthread_mutex_unlock(&mutex1);
    }
    pthread_exit(NULL);
}

void *worker2(void *arg) {
    int i;
    for (i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex2);
        data2++;
        pthread_mutex_unlock(&mutex2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int ret;

    // 뮤텍스 초기화
    if ((ret = pthread_mutex_init(&mutex1, NULL)) != 0) {
        printf("mutex1 init error: %s\n", strerror(ret));
        return 1;
    }
    if ((ret = pthread_mutex_init(&mutex2, NULL)) != 0) {
        printf("mutex2 init error: %s\n", strerror(ret));
        return 1;
    }

    // 스레드 생성
    if ((ret = pthread_create(&t1, NULL, worker1, NULL)) != 0) {
        printf("thread1 create error: %s\n", strerror(ret));
        return 1;
    }
    if ((ret = pthread_create(&t2, NULL, worker2, NULL)) != 0) {
        printf("thread2 create error: %s\n", strerror(ret));
        return 1;
    }

    // 스레드 종료 대기
    if ((ret = pthread_join(t1, NULL)) != 0) {
        printf("thread1 join error: %s\n", strerror(ret));
        return 1;
    }
    if ((ret = pthread_join(t2, NULL)) != 0) {
        printf("thread2 join error: %s\n", strerror(ret));
        return 1;
    }

    // 뮤텍스 삭제
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    printf("data1: %d, data2: %d\n", data1, data2);
    return 0;
}