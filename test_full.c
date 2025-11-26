/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:00:00 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/26 17:00:00 by vdarsuye         ###   ########. fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

static int g_total = 0;
static int g_passed = 0;
static int g_failed = 0;

void check_result(int ret1, int ret2)
{
	g_total++;
	if (ret1 == ret2)
	{
		g_passed++;
		printf(GREEN "✔ OK" RESET " len=%d\n", ret1);
	}
	else
	{
		g_failed++;
		printf(RED "✘ FAIL" RESET " orig=%d user=%d\n", ret1, ret2);
	}
}

void test_mandatory(void)
{
	char *null_str;
	void *null_ptr;
	int a;
	int ret1;
	int ret2;

	null_str = NULL;
	null_ptr = NULL;
	a = 42;

	printf(YELLOW "\n════════════════════════════════════════════\n");
	printf("         MANDATORY PART TESTS\n");
	printf("════════════════════════════════════════════\n" RESET);

	printf(BLUE "\n── %%c (char) ──\n" RESET);
	
	printf("char 'a'                  → ");
	ret1 = printf("%c", 'a');
	printf(" vs ");
	ret2 = ft_printf("%c", 'a');
	printf(" → ");
	check_result(ret1, ret2);

	printf("char 0                    → ");
	ret1 = printf("%c", 0);
	printf(" vs ");
	ret2 = ft_printf("%c", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf("multiple chars            → ");
	ret1 = printf("%c%c%c", 'A', 'B', 'C');
	printf(" vs ");
	ret2 = ft_printf("%c%c%c", 'A', 'B', 'C');
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%s (string) ──\n" RESET);
	
	printf("string 'Hello'            → ");
	ret1 = printf("%s", "Hello");
	printf(" vs ");
	ret2 = ft_printf("%s", "Hello");
	printf(" → ");
	check_result(ret1, ret2);

	printf("string NULL               → ");
	ret1 = printf("%s", null_str);
	printf(" vs ");
	ret2 = ft_printf("%s", null_str);
	printf(" → ");
	check_result(ret1, ret2);

	printf("empty string              → ");
	ret1 = printf("%s", "");
	printf(" vs ");
	ret2 = ft_printf("%s", "");
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%d / %%i (int) ──\n" RESET);
	
	printf("int 42                    → ");
	ret1 = printf("%d", 42);
	printf(" vs ");
	ret2 = ft_printf("%d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("int -42                   → ");
	ret1 = printf("%i", -42);
	printf(" vs ");
	ret2 = ft_printf("%i", -42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("int 0                     → ");
	ret1 = printf("%d", 0);
	printf(" vs ");
	ret2 = ft_printf("%d", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf("int INT_MAX               → ");
	ret1 = printf("%d", INT_MAX);
	printf(" vs ");
	ret2 = ft_printf("%d", INT_MAX);
	printf(" → ");
	check_result(ret1, ret2);

	printf("int INT_MIN               → ");
	ret1 = printf("%i", INT_MIN);
	printf(" vs ");
	ret2 = ft_printf("%i", INT_MIN);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%u (unsigned) ──\n" RESET);
	
	printf("unsigned 42               → ");
	ret1 = printf("%u", 42);
	printf(" vs ");
	ret2 = ft_printf("%u", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("unsigned 0                → ");
	ret1 = printf("%u", 0);
	printf(" vs ");
	ret2 = ft_printf("%u", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf("unsigned UINT_MAX         → ");
	ret1 = printf("%u", UINT_MAX);
	printf(" vs ");
	ret2 = ft_printf("%u", UINT_MAX);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%x / %%X (hex) ──\n" RESET);
	
	printf("hex 42 lowercase          → ");
	ret1 = printf("%x", 42);
	printf(" vs ");
	ret2 = ft_printf("%x", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("hex 42 uppercase          → ");
	ret1 = printf("%X", 42);
	printf(" vs ");
	ret2 = ft_printf("%X", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("hex 0                     → ");
	ret1 = printf("%x", 0);
	printf(" vs ");
	ret2 = ft_printf("%x", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf("hex UINT_MAX              → ");
	ret1 = printf("%x", UINT_MAX);
	printf(" vs ");
	ret2 = ft_printf("%x", UINT_MAX);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%p (pointer) ──\n" RESET);
	
	printf("pointer &a                → ");
	ret1 = printf("%p", &a);
	printf(" vs ");
	ret2 = ft_printf("%p", &a);
	printf(" → ");
	check_result(ret1, ret2);

	printf("pointer NULL              → ");
	ret1 = printf("%p", null_ptr);
	printf(" vs ");
	ret2 = ft_printf("%p", null_ptr);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%%% (percent) ──\n" RESET);
	
	printf("percent                   → ");
	ret1 = printf("%%");
	printf(" vs ");
	ret2 = ft_printf("%%");
	printf(" → ");
	check_result(ret1, ret2);

	printf("multiple percent          → ");
	ret1 = printf("%%%%%%");
	printf(" vs ");
	ret2 = ft_printf("%%%%%%");
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── MIXED ──\n" RESET);
	
	printf("combo                     → ");
	ret1 = printf("c=%c s=%s d=%d", 'X', "test", 42);
	printf(" vs ");
	ret2 = ft_printf("c=%c s=%s d=%d", 'X', "test", 42);
	printf(" → ");
	check_result(ret1, ret2);
}

void test_bonus(void)
{
	char *null_str;
	void *null_ptr;
	int ret1;
	int ret2;

	null_str = NULL;
	null_ptr = NULL;

	printf(YELLOW "\n════════════════════════════════════════════\n");
	printf("           BONUS PART TESTS\n");
	printf("════════════════════════════════════════════\n" RESET);

	printf(BLUE "\n── %%c with flags ──\n" RESET);
	
	printf("%%-5c                     → ");
	ret1 = printf("%-5c", 'z');
	printf(" vs ");
	ret2 = ft_printf("%-5c", 'z');
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%5c                      → ");
	ret1 = printf("%5c", 'z');
	printf(" vs ");
	ret2 = ft_printf("%5c", 'z');
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%s with flags ──\n" RESET);
	
	printf("%%. 3s                     → ");
	ret1 = printf("%.3s", "Hello");
	printf(" vs ");
	ret2 = ft_printf("%.3s", "Hello");
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%10s                     → ");
	ret1 = printf("%10s", "Hello");
	printf(" vs ");
	ret2 = ft_printf("%10s", "Hello");
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%-10s                    → ");
	ret1 = printf("%-10s", "Hello");
	printf(" vs ");
	ret2 = ft_printf("%-10s", "Hello");
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%10.3s                   → ");
	ret1 = printf("%10.3s", "Hello");
	printf(" vs ");
	ret2 = ft_printf("%10.3s", "Hello");
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%s NULL                  → ");
	ret1 = printf("%20.5s", null_str);
	printf(" vs ");
	ret2 = ft_printf("%20.5s", null_str);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%d with + flag ──\n" RESET);
	
	printf("%%+d positive             → ");
	ret1 = printf("%+d", 42);
	printf(" vs ");
	ret2 = ft_printf("%+d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%+d negative             → ");
	ret1 = printf("%+d", -42);
	printf(" vs ");
	ret2 = ft_printf("%+d", -42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%+d zero                 → ");
	ret1 = printf("%+d", 0);
	printf(" vs ");
	ret2 = ft_printf("%+d", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%d with space ──\n" RESET);
	
	printf("%% d positive             → ");
	ret1 = printf("% d", 42);
	printf(" vs ");
	ret2 = ft_printf("% d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%% d negative             → ");
	ret1 = printf("% d", -42);
	printf(" vs ");
	ret2 = ft_printf("% d", -42);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%d with 0 flag ──\n" RESET);
	
	printf("%%05d                     → ");
	ret1 = printf("%05d", 42);
	printf(" vs ");
	ret2 = ft_printf("%05d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%010d                    → ");
	ret1 = printf("%010d", -123);
	printf(" vs ");
	ret2 = ft_printf("%010d", -123);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%d with precision ──\n" RESET);
	
	printf("%%.5d                     → ");
	ret1 = printf("%.5d", 42);
	printf(" vs ");
	ret2 = ft_printf("%.5d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%.0d zero                → ");
	ret1 = printf("%.0d", 0);
	printf(" vs ");
	ret2 = ft_printf("%.0d", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%d combo ──\n" RESET);
	
	printf("%%10.5d                   → ");
	ret1 = printf("%10.5d", 42);
	printf(" vs ");
	ret2 = ft_printf("%10.5d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%-10.5d                  → ");
	ret1 = printf("%-10.5d", 42);
	printf(" vs ");
	ret2 = ft_printf("%-10.5d", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%x with # flag ──\n" RESET);
	
	printf("%%#x                      → ");
	ret1 = printf("%#x", 42);
	printf(" vs ");
	ret2 = ft_printf("%#x", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%#x zero                 → ");
	ret1 = printf("%#x", 0);
	printf(" vs ");
	ret2 = ft_printf("%#x", 0);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%#10x                    → ");
	ret1 = printf("%#10x", 42);
	printf(" vs ");
	ret2 = ft_printf("%#10x", 42);
	printf(" → ");
	check_result(ret1, ret2);

	printf(BLUE "\n── %%p with flags ──\n" RESET);
	
	printf("%%20p                     → ");
	ret1 = printf("%20p", &null_ptr);
	printf(" vs ");
	ret2 = ft_printf("%20p", &null_ptr);
	printf(" → ");
	check_result(ret1, ret2);

	printf("%%-20p NULL              → ");
	ret1 = printf("%-20p", null_ptr);
	printf(" vs ");
	ret2 = ft_printf("%-20p", null_ptr);
	printf(" → ");
	check_result(ret1, ret2);
}

void print_summary(void)
{
	printf(MAGENTA "\n════════════════════════════════════════════\n");
	printf("              TEST SUMMARY\n");
	printf("════════════════════════════════════════════\n" RESET);
	
	printf("\n");
	printf("  Total:   %s%3d%s\n", CYAN, g_total, RESET);
	printf("  Passed:  %s%3d%s\n", GREEN, g_passed, RESET);
	printf("  Failed:  %s%3d%s\n", RED, g_failed, RESET);
	printf("\n");
	
	if (g_failed == 0)
	{
		printf(GREEN "  🎉 ALL TESTS PASSED! 🎉\n" RESET);
		printf(GREEN "  Молодец, Валерка! 💪🔥\n" RESET);
	}
	else
	{
		printf(RED "  ⚠️  %d test(s) failed\n" RESET, g_failed);
		printf("  Success: %.1f%%\n", (float)g_passed / g_total * 100);
	}
	printf("\n");
}

int main(void)
{
	setbuf(stdout, NULL);

	printf(MAGENTA "\n");
	printf("════════════════════════════════════════════\n");
	printf("     FT_PRINTF COMPLETE TEST SUITE\n");
	printf("════════════════════════════════════════════\n");
	printf(RESET);

	test_mandatory();
	test_bonus();
	print_summary();

	return (0);
}
