#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    while (1) {
        printf("\n");
        printf("Выберите задание:\n");
        printf("1 — Вычисление f(x) = sin(x)/x на (0, 4]\n");
        printf("2 — Сумма N чисел Фибоначчи до MAX\n");
        printf("3 — Кредитные платежи\n");
        printf("0 — Выход\n");
        printf("Введите номер: ");
        scanf("%d", &choice);

        // Очистка буфера ввода (чтобы getchar() работал корректно)
        while (getchar() != '\n');

        if (choice == 0) {
            printf("Выход из программы.\n");
            break;
        }

        if (choice == 1) {
            printf("\n--- Задание II.1: f(x) = sin(x)/x ---\n");
            printf("x\t\tf(x)\n");
            printf("--------------------------\n");

            double a = 0.0, b = 4.0;
            double h = (b - a) / 10.0;

            for (int i = 1; i <= 10; ++i) {
                double x = a + i * h;
                double fx = sin(x) / x;
                printf("%.2f\t\t%.6f\n", x, fx);
            }
        }
        else if (choice == 2) {
            printf("\n--- Задание II.2: Числа Фибоначчи ---\n");
            long long MAX;
            printf("Введите MAX: ");
            scanf("%lld", &MAX);

            if (MAX < 0) {
                printf("MAX должен быть >= 0.\n");
            }
            else {
                long long f0 = 0, f1 = 1;
                long long sum = 0;
                int N = 0;

                while (1) {
                    long long current;
                    if (N == 0) {
                        current = 0;
                    }
                    else if (N == 1) {
                        current = 1;
                    }
                    else {
                        current = f0 + f1;
                        f0 = f1;
                        f1 = current;
                    }

                    if (sum + current > MAX) {
                        break;
                    }

                    sum += current;
                    N++;

                    if (N == 1) {
                        f0 = 0;
                        f1 = 1;
                    }
                }

                printf("N = %d, S = %lld\n", N, sum);
            }
        }
        else if (choice == 3) {
            printf("\n--- Задание II.3: Кредитные платежи ---\n");
            double summa;
            int months;
            double rate_year;

            printf("Сумма (руб.) -> ");
            scanf("%lf", &summa);
            printf("Срок (мес.) -> ");
            scanf("%d", &months);
            printf("Процентная ставка (годовых) -> ");
            scanf("%lf", &rate_year);

            double rate_month = rate_year / 100.0 / 12.0;
            double principal = summa / months;

            printf("\n");
            printf("%-5s %-12s %-10s %-10s\n", "№", "Долг", "Процент", "Платеж");
            printf("%s\n", "--------------------------------------------------");

            double total_interest = 0.0;
            double remaining = summa;

            for (int i = 1; i <= months; ++i) {
                double interest = remaining * rate_month;
                interest = (double)((long long)(interest * 100 + 0.5)) / 100.0;
                double payment = principal + interest;
                payment = (double)((long long)(payment * 100 + 0.5)) / 100.0;

                printf("%-5d %-12.2f %-10.2f %-10.2f\n", i, remaining, interest, payment);

                total_interest += interest;
                remaining -= principal;
            }

            total_interest = (double)((long long)(total_interest * 100 + 0.5)) / 100.0;
            printf("\nВсего процентов: %.2f\n", total_interest);
        }
        else {
            printf("Неверный выбор. Попробуйте снова.\n");
        }

        // Пауза перед возвратом в меню
        printf("\nНажмите Enter для возврата в меню...");
        getchar(); // Ждём нажатия Enter
    }

    return 0;
}