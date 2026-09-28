
################################################################

include $(BASE_DIR)/fancy.mk

################################################################

all:
	@$(MAKE) -s other_all

clean:
	@$(MAKE) -s other_clean

fclean:
	@$(MAKE) -s other_fclean

re:
	@$(MAKE) -s other_re

.PHONY: all clean fclean re

################################################################

include $(BASE_DIR)/other.mk

################################################################

ifndef BASE_DIR
$(error missing BASE_DIR)
endif

################################################################
