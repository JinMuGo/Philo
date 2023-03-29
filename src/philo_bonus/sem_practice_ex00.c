/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_practice_ex00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:56:04 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 15:56:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SHARED_MEMORY_SIZE 1024
#define SEM_NAME "/my_semaphore"

int main() {
  int shm_fd;
  char *shm_ptr;

  // 공유 메모리 세그먼트 생성
  shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, SHARED_MEMORY_SIZE);
  shm_ptr = (char*) mmap(0, SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  // 세마포어 생성 및 초기화
  sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);

  // 세마포어 이용한 동기화
  sem_wait(sem);
  sprintf(shm_ptr, "Hello, semaphore!");
  printf("Message written to shared memory\n");
  sem_post(sem);

  // 세마포어 제거
  sem_close(sem);
  sem_unlink(SEM_NAME);


  // 공유 메모리 세그먼트 제거
  munmap(shm_ptr, SHARED_MEMORY_SIZE);
  shm_unlink("/my_shm");

  return 0;
}