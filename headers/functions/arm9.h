#ifndef HEADERS_FUNCTIONS_ARM9_H_
#define HEADERS_FUNCTIONS_ARM9_H_

#include "arm9/itcm.h"

void EntryArm9(void);
void InitMemAllocTable(void);
void SetMemAllocatorParams(get_alloc_arena_fn_t get_alloc_arena,
                           get_free_arena_fn_t get_free_arena);
struct mem_arena* GetAllocArenaDefault(struct mem_arena* arena, uint32_t flags);
struct mem_arena* GetFreeArenaDefault(struct mem_arena* arena, uint32_t flags);
void InitMemArena(struct mem_arena* arena, struct iovec* mem, struct mem_block* blocks,
                  uint32_t max_blocks);
uint32_t MemAllocFlagsToBlockType(uint32_t alloc_flags);
int FindAvailableMemBlock(struct mem_arena* arena, uint32_t alloc_flags, uint32_t len);
struct mem_block* SplitMemBlock(struct mem_arena* arena, uint32_t idx, uint32_t alloc_flags,
                                uint32_t len, uint32_t user_flags);
void* MemAlloc(uint32_t len, uint32_t flags);
void MemFree(void* ptr);
struct mem_arena* MemArenaAlloc(struct mem_arena* parent_arena, uint32_t len, uint32_t max_blocks,
                                uint32_t flags);
struct mem_arena* CreateMemArena(struct iovec* mem, uint32_t max_blocks);
void* MemLocateSet(struct mem_arena* arena, uint32_t len, uint32_t flags);
void MemLocateUnset(struct mem_arena* arena, void* ptr);
int RoundUpDiv256(int x);
int MultiplyByFixedPoint(int x, int mult_fp);
uint32_t UMultiplyByFixedPoint(uint32_t x, uint32_t mult_fp);
uint16_t GetRngSeed(void);
void SetRngSeed(uint16_t seed);
uint16_t Rand16Bit(void);
uint32_t RandInt(uint32_t n);
int RandRange(int x, int y);
uint32_t Rand32Bit(void);
uint32_t RandIntSafe(uint32_t n);
int RandRangeSafe(int x, int y);
void WaitForever(void);
uint16_t InterruptMasterDisable(void);
uint16_t InterruptMasterEnable(void);
void InitMemAllocTableVeneer(void);
void ZInit8(void* ptr);
bool PointsToZero(int* ptr);
void MemZero(void* ptr, uint32_t len);
void MemZero16(void* ptr, int len);
void MemZero32(void* ptr, int len);
void MemsetSimple(void* ptr, char val, uint32_t len);
void Memset32(void* ptr, int val, int len);
void MemcpySimple(void* dest, void* src, uint32_t n);
void Memcpy16(void* dest, void* src, int n);
void Memcpy32(void* dest, void* src, int n);
void TaskProcBoot(void);
bool EnableAllInterrupts(void);
float GetTime(void);
bool DisableAllInterrupts(void);
bool SoundResume(void);
void CardPullOutWithStatus(int status);
void CardPullOut(void);
void CardBackupError(void);
void HaltProcessDisp(int status);
bool OverlayIsLoaded(enum overlay_group_id group_id);
void LoadOverlay(enum overlay_group_id group_id);
void UnloadOverlay(enum overlay_group_id group_id);
float EuclideanNorm(int* vec2);
void ClampComponentAbs(int* vec2, int max);
bool GetHeldButtons(int controller, undefined* btn_ptr);
bool GetPressedButtons(int controller, undefined* btn_ptr);
bool GetReleasedStylus(undefined* stylus_ptr);
void KeyWaitInit(void);
void DataTransferInit(void);
void DataTransferStop(void);
void FileInitVeneer(struct file_stream* file);
void FileOpen(struct file_stream* file, const char* filepath);
uint32_t FileGetSize(struct file_stream* file);
uint32_t FileRead(struct file_stream* file, void* buf, uint32_t size);
void FileSeek(struct file_stream* file, int offset, int whence);
void FileClose(struct file_stream* file);
void UnloadFile(void* ptr);
void LoadFileFromRom(struct iovec* iov, const char* filepath, uint32_t flags);
uint32_t GetDebugFlag1(uint32_t flag_id);
void SetDebugFlag1(uint32_t flag_id, uint32_t val);
int AppendProgPos(char* str, struct prog_pos_info* prog_pos, const char* msg);
void DebugPrintTrace(const char* msg, struct prog_pos_info* prog_pos);
void DebugPrint0(const char* fmt, ...);
uint32_t GetDebugFlag2(uint32_t flag_id);
void SetDebugFlag2(uint32_t flag_id, uint32_t val);
void DebugPrint(uint8_t level, const char* fmt, ...);
void FatalError(struct prog_pos_info prog_pos, const char* fmt, ...);
void OpenAllPackFiles(void);
uint32_t GetFileLengthInPackWithPackNb(enum pack_file_id pack_id, uint32_t file_index);
uint32_t LoadFileInPackWithPackId(enum pack_file_id pack_id, void* output_buffer,
                                  uint32_t file_index);
void AllocAndLoadFileInPack(enum pack_file_id pack_id, uint32_t file_index,
                            struct pack_alloc_and_load_result* output, uint32_t malloc_flags);
void OpenPackFile(struct pack_file_opened* pack_file, const char* file_name);
uint32_t GetFileLengthInPack(struct pack_file_opened* pack_file, uint32_t file_index);
union damage_source GetDamageSource(enum move_id, enum item_id);
uint32_t LoadFileInPack(struct pack_file_opened* pack_file, void* output_buffer,
                        uint32_t file_index);
enum item_category GetItemCategoryVeneer(enum item_id item_id);
enum move_id GetItemMoveId16(enum item_id item_id);
bool IsThrownItem(enum item_id item_id);
bool IsNotMoney(enum item_id item_id);
bool IsEdible(enum item_id item_id);
bool IsHM(enum item_id item_id);
bool IsGummi(enum item_id item_id);
bool IsAuraBow(enum item_id item_id);
void InitItem(struct item* item, enum item_id item_id, uint16_t quantity, bool sticky);
void InitStandardItem(struct item* item, enum item_id item_id, bool sticky);
int GetDisplayedBuyPrice(struct item* item);
int GetDisplayedSellPrice(struct item* item);
int GetActualBuyPrice(struct item* item);
int GetActualSellPrice(struct item* item);
int FindItemInInventory(enum item_id item_id);
int SprintfStatic(char* str, const char* format, ...);
void ItemZInit(struct item* item);
int WriteItemsToSave(void* start_address, uint32_t total_length);
int ReadItemsFromSave(void* start_address, uint32_t total_length);
bool IsItemAvailableInDungeonGroup(enum dungeon_id dungeon_id, enum item_id item_id);
enum item_id GetItemIdFromList(int list_id, int category_num, int item_num);
enum item_id NormalizeTreasureBox(enum item_id item_id);
void RemoveEmptyItems(struct item* list, int size);
void LoadItemPspi2n(void);
uint8_t GetExclusiveItemType(enum item_id item_id);
int GetExclusiveItemOffsetEnsureValid(enum item_id item_id);
bool IsItemValid(enum item_id item_id);
int16_t GetExclusiveItemParameter(enum item_id item_id);
enum item_category GetItemCategory(enum item_id item_id);
enum item_id EnsureValidItem(enum item_id);
char* GetItemName(enum item_id item_id);
void GetItemNameFormatted(char* name_out, enum item_id item_id, bool flag1, bool flag2);
uint16_t GetItemBuyPrice(enum item_id item_id);
uint16_t GetItemSellPrice(enum item_id item_id);
uint8_t GetItemSpriteId(enum item_id item_id);
uint8_t GetItemPaletteId(enum item_id item_id);
uint8_t GetItemActionName(enum item_id item_id);
uint8_t GetThrownItemQuantityLimit(enum item_id, int limit_idx);
enum move_id GetItemMoveId(enum item_id item_id);
bool TestItemFlag0xE(enum item_id item_id, int bit_id);
bool IsItemInTimeDarkness(enum item_id item_id);
bool IsItemValidVeneer(enum item_id item_id);
void SetGold(int val);
int GetGold(void);
void SetMoneyCarried(int amount);
int GetCurrentBagCapacity(void);
bool IsBagFull(void);
int GetNbItemsInBag(void);
int CountNbItemsOfTypeInBag(enum item_id item_id);
int CountItemTypeInBag(enum item_id item_id);
bool IsItemInBag(enum item_id item_id);
bool IsItemWithFlagsInBag(enum item_id item_id, int flags);
bool IsItemInTreasureBoxes(enum item_id item_id);
bool IsHeldItemInBag(struct item* item);
bool IsItemForSpecialSpawnInBag(void);
bool HasStorableItems(void);
int GetItemIndex(struct item* item);
int GetEquivItemIndex(struct item* item);
int GetEquippedThrowableItem(void);
int GetFirstUnequippedItemOfType(enum item_id item_id);
bool CopyItemAtIdx(int idx, struct item* item_out);
struct item* GetItemAtIdx(int idx);
void RemoveEmptyItemsInBag(void);
bool RemoveItemNoHole(int idx);
void RemoveItem(int idx);
void RemoveHeldItemNoHole(int held_idx);
bool RemoveItemByIdAndStackNoHole(struct item* item);
bool RemoveEquivItem(struct item* item);
bool RemoveEquivItemNoHole(struct item* item);
bool DecrementStackItem(struct item* item);
bool RemoveItemNoHoleCheck(int idx);
bool RemoveFirstUnequippedItemOfType(enum item_id item_id);
void RemoveAllItems(void);
void RemoveAllItemsStartingAt(int idx);
bool SpecialProcAddItemToBag(struct bulk_item* item);
bool AddItemToBagNoHeld(struct item* item);
bool AddItemToBag(struct item* item, int held_by);
bool ScriptSpecialProcess0x39(void);
int CountItemTypeInStorage(struct bulk_item* item);
bool RemoveItemsTypeInStorage(struct bulk_item* item);
bool AddItemToStorage(struct bulk_item* item);
void SetMoneyStored(int amount);
void GetKecleonItems1(int param_1);
void GetKecleonItems2(int param_1);
int GetExclusiveItemOffset(enum item_id item_id);
void ApplyExclusiveItemStatBoosts(enum item_id item_id, uint8_t* atk_boost, uint8_t* sp_atk_boost,
                                  uint8_t* def_boost, uint8_t* sp_def_boost);
void SetExclusiveItemEffect(uint32_t* effect_flags, enum exclusive_item_effect_id effect_id);
bool ExclusiveItemEffectFlagTest(uint32_t* effect_flags, enum exclusive_item_effect_id effect_id);
bool IsExclusiveItemIdForMonster(enum item_id item_id, enum monster_id monster_id,
                                 enum type_id type1, enum type_id type2);
bool IsExclusiveItemForMonster(struct item* item, enum monster_id monster_id, enum type_id type1,
                               enum type_id type2);
enum item_id BagHasExclusiveItemTypeForMonster(int excl_type, enum monster_id monster_id,
                                               enum type_id type1, enum type_id type2);
int ProcessGinsengOverworld(undefined* target, struct move_id_16* move_id_out, int* move_boost_out);
void ApplyGummiBoostsGroundMode(undefined2* param_1, undefined2* param_2, undefined* param_3,
                                undefined* param_4, undefined2 param_5, undefined param_6,
                                void* buffer);
bool LoadSynthBin(void);
void CloseSynthBin(void);
undefined* GetSynthItem(int param_1);
void LoadWazaP(void);
void LoadWazaP2(void);
void UnloadCurrentWazaP(void);
char* GetMoveName(enum move_id move_id);
void FormatMoveString(char* string, struct move* move, undefined* type_print);
void FormatMoveStringMore(undefined* param_1, int param_2, struct move* move,
                          undefined* type_print);
void InitMove(struct move* move, enum move_id);
struct move_target_and_range GetMoveTargetAndRange(struct move* move, bool is_ai);
void GetInfoMoveCheckId(struct move* move, enum move_id move_id);
void GetInfoMoveGround(struct ground_move* move, enum move_id move_id);
enum type_id GetMoveType(struct move* move);
undefined* GetMovesetLevelUpPtr(enum monster_id monster_id);
bool IsInvalidMoveset(int moveset_id);
undefined* GetMovesetHmTmPtr(enum monster_id monster_id);
undefined* GetMovesetEggPtr(enum monster_id monster_id);
uint8_t GetMoveAiWeight(struct move* move);
uint8_t GetMoveNbStrikes(struct move* move);
int GetMoveBasePower(struct move* move);
int16_t GetMoveBasePowerGround(struct ground_move* move);
uint8_t GetMoveAccuracyOrAiChance(struct move* move, int which);
uint8_t GetMoveBasePp(struct move* move);
int GetMaxPp(struct move* move);
uint8_t GetMoveMaxGinsengBoost(struct move* move);
uint8_t GetMoveMaxGinsengBoostGround(struct ground_move* move);
int GetMoveCritChance(struct move* move);
bool IsThawingMove(struct move* move);
bool IsAffectedByTaunt(struct move* move);
uint8_t GetMoveRangeId(struct move* move);
int GetMoveActualAccuracy(enum move_id move_id);
int GetMoveBasePowerFromId(enum move_id move_id);
bool IsMoveRangeString19(struct move* move);
char* GetMoveMessageFromId(enum move_id move_id);
int GetNbMoves(undefined* moveset);
int GetMovesetIdx(undefined* moveset, enum move_id move_id);
bool IsReflectedByMagicCoat(enum move_id move_id);
bool CanBeSnatched(enum move_id move_id);
bool FailsWhileMuzzled(enum move_id move_id);
bool IsSoundMove(struct move* move);
bool IsRecoilMove(enum move_id move_id);
void AllManip1(undefined4 param_1);
void AllManip2(undefined4 param_1);
void ManipMoves1v1(undefined* param_1, undefined* param_2);
void ManipMoves1v2(undefined* param_1, undefined* param_2);
void ManipMoves2v1(undefined* param_1, undefined* param_2);
void ManipMoves2v2(undefined* param_1, undefined* param_2);
void DungeonMoveToGroundMove(struct ground_move* dst, struct move* src);
void GroundToDungeonMoveset(undefined* dst, undefined* src);
void DungeonToGroundMoveset(undefined* dst, undefined* src);
void GetInfoGroundMoveset(undefined* moveset, struct move_id_16* moves);
int FindFirstFreeMovesetIdx(undefined* moveset);
void LearnMoves(undefined* moveset, struct move_id_16* moves);
void CopyMoveTo(undefined* write_info, void* buffer_write);
void CopyMoveFrom(undefined* read_info, void* buffer_read);
void CopyMovesetTo(undefined* write_info, void* buffer_write);
void CopyMovesetFrom(undefined* read_info, void* buffer_read);
bool Is2TurnsMove(enum move_id move_id);
bool IsRegularAttackOrProjectile(enum move_id move_id);
bool IsPunchMove(enum move_id move_id);
bool IsHealingWishOrLunarDance(enum move_id move_id);
bool IsCopyingMove(enum move_id move_id);
bool IsTrappingMove(enum move_id move_id);
bool IsOneHitKoMove(enum move_id move_id);
bool IsNot2TurnsMoveOrSketch(enum move_id move_id);
bool IsRealMove(enum move_id move_id);
bool IsMovesetValid(undefined* moveset);
bool IsRealMoveInTimeDarkness(enum move_id move_id);
bool IsMovesetValidInTimeDarkness(undefined* moveset);
int GetFirstNotRealMoveInTimeDarkness(undefined* moveset);
bool IsSameMove(undefined* moveset, struct move* move);
enum move_category GetMoveCategory(enum move_id move_id);
int GetPpIncrease(enum monster_id monster_id, uint32_t* iq_skill_flags);
void OpenWaza(int waza_id);
void SelectWaza(int waza_id);
void ManipBgmPlayback(void);
void SoundDriverReset(void);
uint32_t LoadDseFile(struct iovec* iov, const char* filename);
undefined4 PlaySeLoad(int param_1);
void PlayBgm(int param_1, int param_2, int param_3);
void StopBgm(int param_1);
void ChangeBgm(int param_1, int param_2);
void PlayBgm2(int param_1, int param_2, int param_3);
void StopBgm2(int param_1);
void ChangeBgm2(int param_1, int param_2);
void PlayME(int param_1, int param_2, int param_3);
void StopME(int fade_out);
void PlaySe(int param_1, int param_2);
void PlaySeFullSpec(int param_1, int param_2, int param_3, int param_4);
void SeChangeVolume(int param_1, int param_2, int param_3);
void SeChangePan(int param_1, int param_2, int param_3);
void StopSe(int param_1, int param_2);
void DeleteWanTableEntry(undefined* wan_table, int wan_id);
int FindWanTableEntry(undefined* wan_table, const char* path);
int GetLoadedWanTableEntry(undefined* wan_table, int bin_file_id, int file_id);
int LoadWanTableEntry(undefined* wan_table, const char* path, uint32_t flags);
int ReplaceWanFromBinFile(undefined* wan_table, int wan_id, int bin_file_id, int file_id,
                          bool compressed);
void DeleteWanTableEntryVeneer(undefined* wan_table, int wan_id);
void LoadWteFromRom(struct wte_handle* handle, const char* path, uint32_t flags);
void LoadWteFromFileDirectory(struct wte_handle* handle, uint16_t pack_file_id, uint16_t file_index,
                              uint32_t malloc_flags);
void UnloadWte(struct wte_handle* handle);
undefined* LoadWtuFromBin(int bin_file_id, int file_id, int load_type);
void ProcessWte(undefined* header, undefined4 unk_pal, undefined4 unk_tex,
                undefined4 unk_tex_param);
int HandleSir0Translation(uint8_t** dst, uint8_t* src);
void ConvertPointersSir0(undefined* sir0_ptr);
int HandleSir0TranslationVeneer(uint8_t** dst, uint8_t* src);
int DecompressAtNormalVeneer(undefined* addr_decomp, int expected_size, undefined* at_ptr);
int DecompressAtNormal(undefined* addr_decomp, int expected_size, undefined* at_ptr);
int DecompressAtHalf(undefined* addr_decomp, int expected_size, undefined* at_ptr, int high_nibble);
int DecompressAtFromMemoryPointerVeneer(undefined* addr_decomp, int expected_size,
                                        undefined* at_ptr);
int DecompressAtFromMemoryPointer(undefined* addr_decomp, int expected_size, undefined* at_ptr);
void WriteByteFromMemoryPointer(uint8_t byte);
int GetAtSize(undefined* at_ptr, int param_2);
int GetLanguageType(void);
int GetLanguage(void);
bool StrcmpTag(const char* s1, const char* s2);
int StoiTag(const char* s);
int AnalyzeText(undefined* buf);
int PreprocessString(char* output, int output_size, const char* format,
                     struct preprocessor_flags flags, struct preprocessor_args* args);
int PreprocessStringFromMessageId(char* output, int output_size, int message_id,
                                  struct preprocessor_flags flags, struct preprocessor_args* args);
void InitPreprocessorArgs(struct preprocessor_args* args);
char* SetStringAccuracy(char* s, int param_2);
char* SetStringPower(char* s, int param_2);
void SetQuestionMarks(char* s);
void StrcpySimple(char* dest, const char* src);
void StrncpySimple(char* dest, const char* src, uint32_t n);
void StrncpySimpleNoPad(char* dest, const char* src, uint32_t n);
int StrncmpSimple(const char* s1, const char* s2, uint32_t n);
void StrncpySimpleNoPadSafe(char* dest, const char* src, uint32_t n);
void SpecialStrcpy(char* dest, const char* src);
void GetStringFromFile(char* buf, int string_id);
void LoadStringFile(void);
void GetStringFromFileVeneer(char* buf, int string_id);
char* StringFromMessageId(int message_id);
void CopyStringFromMessageId(char* buf, int string_id, int buf_len);
void LoadTblTalk(void);
int GetTalkLine(int personality_idx, int group_id, int restrictions);
void SetScreenWindowsColor(int palette_idx, bool upper_screen);
void SetBothScreensWindowsColor(int palette_idx);
undefined4 GetDialogBoxField0xC(int dbox_id);
int CreateNormalMenu(undefined* layout, int menu_flags, undefined* additional_info, undefined* menu,
                     int option_id);
void FreeNormalMenu(int menu_id);
bool IsNormalMenuActive(int menu_id);
int GetNormalMenuResult(int menu_id);
int CreateAdvancedMenu(undefined* layout, int menu_flags, undefined* additional_info,
                       undefined* entry_fn, int n_options, int n_opt_pp);
void FreeAdvancedMenu(int menu_id);
bool IsAdvancedMenuActive(int menu_id);
int GetAdvancedMenuCurrentOption(int menu_id);
int GetAdvancedMenuResult(int menu_id);
int CreateDBox(undefined* layout);
void FreeDBox(int dbox_id);
bool IsDBoxActive(int dbox_id);
void ShowMessageInDBox(int dbox_id, struct preprocessor_flags flags, int string_id,
                       struct preprocessor_args* args);
void ShowDBox(int dbox_id);
int CreatePortraitBox(undefined param_1, undefined4 param_2, int param_3);
void FreePortraitBox(int dbox_id);
void ShowPortraitBox(int dbox_id, undefined* portrait);
void HidePortraitBox(int dbox_id);
bool IsMenuOptionActive(undefined* param_1);
int ShowKeyboard(int message_id, char* buffer1, int param_3, char* buffer2);
int GetKeyboardStatus(void);
int GetKeyboardStringResult(void);
void PrintMoveOptionMenu(void);
void PrintIqSkillsMenu(enum monster_id monster_id, uint32_t* iq_skills_flags, int monster_iq,
                       bool is_blinded);
bool GetNotifyNote(void);
void SetNotifyNote(bool flag);
void InitMainTeamAfterQuiz(void);
void ScriptSpecialProcess0x3(void);
void ScriptSpecialProcess0x4(void);
void ReadStringSave(char* buf);
bool CheckStringSave(const char* buf);
int WriteSaveFile(undefined* save_info, undefined* buf, int size);
int ReadSaveFile(undefined* save_info, undefined* buf, int size);
void CalcChecksum(int* buf, int size);
bool CheckChecksum(int* buf, int size);
int NoteSaveBase(int param_1);
void WriteQuickSaveInfo(undefined* buf, int size);
undefined4 ReadSaveHeader(undefined4* param_1, undefined4 param_2, undefined4 param_3,
                          undefined4 param_4);
int NoteLoadBase(void);
int ReadQuickSaveInfo(undefined* buf, int size);
int GetGameMode(void);
void InitScriptVariableValues(void);
void InitEventFlagScriptVars(void);
void ZinitScriptVariable(void* local_var_vals, enum script_var_id id);
void LoadScriptVariableRaw(struct script_var_desc* var, void* local_var_vals,
                           enum script_var_id id);
int LoadScriptVariableValue(void* local_var_vals, enum script_var_id id);
int LoadScriptVariableValueAtIndex(void* local_var_vals, enum script_var_id id, int idx);
void SaveScriptVariableValue(void* local_var_vals, enum script_var_id id, int val);
void SaveScriptVariableValueAtIndex(void* local_var_vals, enum script_var_id id, int idx, int val);
int LoadScriptVariableValueSum(void* local_var_vals, enum script_var_id id);
void LoadScriptVariableValueBytes(enum script_var_id id, void* dest, uint32_t n);
void SaveScriptVariableValueBytes(enum script_var_id id, void* src, uint32_t n);
bool ScriptVariablesEqual(void* local_var_vals, enum script_var_id id1, enum script_var_id id2);
void EventFlagBackup(void);
int DumpScriptVariableValues(void* dest);
bool RestoreScriptVariableValues(void* src);
void InitScenarioScriptVars(void);
void SetScenarioScriptVar(enum script_var_id id, uint8_t val0, uint8_t val1);
int GetSpecialEpisodeType(void);
bool HasPlayedOldGame(void);
int GetPerformanceFlagWithChecks(int flag_id);
int GetScenarioBalance(void);
void ScenarioFlagBackup(void);
void InitWorldMapScriptVars(void);
void InitDungeonListScriptVars(void);
void SetDungeonConquest(enum dungeon_id dungeon_id, int bit_value);
int CheckDungeonOpen(enum dungeon_id dungeon_id);
struct global_progress* GlobalProgressAlloc(void);
void ResetGlobalProgress(void);
void SetMonsterFlag1(enum monster_id monster_id);
bool GetMonsterFlag1(enum monster_id monster_id);
void SetMonsterFlag2(enum monster_id monster_id);
bool HasMonsterBeenAttackedInDungeons(enum monster_id monster_id);
void SetDungeonTipShown(int tip_id);
bool GetDungeonTipShown(int tip_id);
void SetMaxReachedFloor(enum dungeon_id dungeon_id, int max_floor);
int GetMaxReachedFloor(enum dungeon_id dungeon_id);
void IncrementNbAdventures(void);
int GetNbAdventures(void);
bool CanMonsterSpawn(enum monster_id monster_id);
void IncrementExclusiveMonsterCounts(enum monster_id monster_id);
void CopyProgressInfoTo(undefined* write_info, undefined4 param_2, undefined4 param_3, int param_4);
undefined4 CopyProgressInfoFromScratchTo(void* start_addr, uint32_t total_len);
void CopyProgressInfoFrom(undefined* read_info);
undefined4 CopyProgressInfoFromScratchFrom(void* start_addr, uint32_t total_len);
void SetPortraitMonsterId(undefined* portrait, enum monster_id monster_id);
void SetPortraitExpressionId(undefined* portrait, int expression_id);
void SetPortraitUnknownAttr(undefined* portrait, int attr);
void SetPortraitAttrStruct(undefined* portrait, undefined* attr);
bool LoadPortrait(undefined* portrait, void* buf);
int GetNbFloors(enum dungeon_id dungeon_id);
int GetNbFloorsPlusOne(enum dungeon_id dungeon_id);
enum dungeon_group_id GetDungeonGroup(enum dungeon_id dungeon_id);
int GetNbPrecedingFloors(enum dungeon_id dungeon_id);
int GetNbFloorsDungeonGroup(enum dungeon_id dungeon_id);
void DungeonFloorToGroupFloor(struct dungeon_group_and_group_floor* out_group_data,
                              struct dungeon_floor_pair* dungeon_and_floor);
int GetGroundNameId(int param_1);
void SetAdventureLogStructLocation(void);
void SetAdventureLogDungeonFloor(struct dungeon_floor_pair dungeon_floor);
struct dungeon_floor_pair GetAdventureLogDungeonFloor(void);
void ClearAdventureLogStruct(void);
void SetAdventureLogCompleted(uint32_t entry_id);
bool IsAdventureLogNotEmpty(void);
bool GetAdventureLogCompleted(uint32_t entry_id);
void IncrementNbDungeonsCleared(void);
uint32_t GetNbDungeonsCleared(void);
void IncrementNbFriendRescues(void);
uint32_t GetNbFriendRescues(void);
void IncrementNbEvolutions(void);
uint32_t GetNbEvolutions(void);
void IncrementNbSteals(void);
void IncrementNbEggsHatched(void);
uint32_t GetNbEggsHatched(void);
uint32_t GetNbPokemonJoined(void);
uint32_t GetNbMovesLearned(void);
void SetVictoriesOnOneFloor(uint32_t nb_victories);
uint32_t GetVictoriesOnOneFloor(void);
void SetPokemonJoined(enum monster_id monster_id);
void SetPokemonBattled(enum monster_id monster_id);
uint32_t GetNbPokemonBattled(void);
void IncrementNbBigTreasureWins(void);
void SetNbBigTreasureWins(uint32_t nb_big_treasure_wins);
uint32_t GetNbBigTreasureWins(void);
void SetNbRecycled(uint32_t nb_recycled);
uint32_t GetNbRecycled(void);
void IncrementNbSkyGiftsSent(void);
void SetNbSkyGiftsSent(uint32_t nb_sky_gifts_sent);
uint32_t GetNbSkyGiftsSent(void);
void ComputeSpecialCounters(void);
void RecruitSpecialPokemonLog(enum monster_id monster_id);
void IncrementNbFainted(void);
uint32_t GetNbFainted(void);
void SetItemAcquired(struct item* item);
uint32_t GetNbItemAcquired(void);
void SetChallengeLetterCleared(uint32_t challenge_id);
uint32_t GetSentryDutyGamePoints(int32_t rank);
int32_t SetSentryDutyGamePoints(uint32_t points);
void CopyLogTo(undefined* write_info);
void CopyLogFrom(undefined* read_info);
void GetAbilityString(undefined* buf, enum ability_id ability_id);
int GetAbilityDescStringId(enum ability_id ability_id);
int GetTypeStringId(enum type_id type_id);
void CopyBitsTo(undefined* write_info, void* buf_write, int nbits);
void CopyBitsFrom(undefined* read_info, void* buf_read, int nbits);
void StoreDefaultTeamName(void);
void GetTeamNameCheck(undefined* buf);
void GetTeamName(undefined* buf);
void SetTeamName(undefined* buf);
uint32_t SubFixedPoint(uint32_t val_fp, uint32_t dec_fp);
uint32_t BinToDecFixedPoint(uint32_t* q16);
int CeilFixedPoint(uint32_t val_fp);
bool DungeonGoesUp(enum dungeon_id dungeon_id);
int GetTurnLimit(enum dungeon_id dungeon_id);
bool DoesNotSaveWhenEntering(enum dungeon_id dungeon_id);
bool TreasureBoxDropsEnabled(enum dungeon_id dungeon_id);
bool IsLevelResetDungeon(enum dungeon_id dungeon_id);
int GetMaxItemsAllowed(enum dungeon_id dungeon_id);
bool IsMoneyAllowed(enum dungeon_id dungeon_id);
int8_t GetMaxRescueAttempts(enum dungeon_id dungeon_id);
bool IsRecruitingAllowed(enum dungeon_id dungeon_id);
bool GetLeaderChangeFlag(enum dungeon_id dungeon_id);
int GetUnknownDungeonOption(enum dungeon_id dungeon_id);
bool CanEnemyEvolve(enum dungeon_id dungeon_id);
int GetMaxMembersAllowed(enum dungeon_id dungeon_id);
bool IsIqEnabled(enum dungeon_id dungeon_id);
bool IsTrapInvisibleWhenAttacking(enum dungeon_id dungeon_id);
bool JoinedAtRangeCheck(struct dungeon_id_8 joined_at);
bool IsDojoDungeon(enum dungeon_id dungeon_id);
bool IsFutureDungeon(enum dungeon_id dungeon_id);
bool IsSpecialEpisodeDungeon(enum dungeon_id dungeon_id);
enum item_id RetrieveFromItemList1(undefined* dungeon_info, undefined4 param_2);
bool IsForbiddenFloor(undefined* dungeon_info, undefined4 param_2, undefined4 param_3,
                      undefined4 param_4);
void Copy16BitsFrom(undefined* read_info, void* buf_read);
enum item_id RetrieveFromItemList2(undefined* dungeon_info, undefined4 param_2);
bool IsInvalidForMission(enum dungeon_id dungeon_id);
bool IsExpEnabledInDungeon(enum dungeon_id dungeon_id);
bool IsSkyExclusiveDungeon(enum dungeon_id dungeon_id);
bool JoinedAtRangeCheck2(struct dungeon_id_8 joined_at);
uint32_t GetBagCapacity(int scenario_balance);
uint32_t GetBagCapacitySpecialEpisode(int se_type);
struct rankup_table_entry* GetRankUpEntry(int rank);
int GetBgRegionArea(int offset, int subregion_id, int region_id);
void LoadMonsterMd(void);
void GetNameRaw(char* dst, enum monster_id monster_id);
void GetName(char* dst, enum monster_id monster_id, char color_id);
void GetNameWithGender(char* dst, enum monster_id monster_id, char color_id);
void GetSpeciesString(char* dst, enum monster_id monster_id);
char* GetNameString(enum monster_id monster_id);
int GetSpriteIndex(enum monster_id monster_id);
int GetDexNumber(enum monster_id monster_id);
char* GetCategoryString(enum monster_id monster_id);
enum monster_gender GetMonsterGender(enum monster_id monster_id);
int GetBodySize(enum monster_id monster_id);
uint8_t GetSpriteSize(enum monster_id monster_id);
uint8_t GetSpriteFileSize(enum monster_id monster_id);
int GetShadowSize(enum monster_id monster_id);
int GetSpeedStatus(enum monster_id monster_id);
int GetMovementType(enum monster_id monster_id);
int GetRegenSpeed(enum monster_id monster_id);
bool GetCanMoveFlag(enum monster_id monster_id);
int GetChanceAsleep(enum monster_id monster_id);
int GetLowKickMultiplier(enum monster_id monster_id);
int GetSize(enum monster_id monster_id);
int GetBaseHp(enum monster_id monster_id);
bool CanThrowItems(enum monster_id monster_id);
bool CanEvolve(enum monster_id monster_id);
enum monster_id GetMonsterPreEvolution(enum monster_id monster_id);
int GetBaseOffensiveStat(enum monster_id monster_id, int stat_idx);
int GetBaseDefensiveStat(enum monster_id monster_id, int stat_idx);
int GetType(enum monster_id monster_id, int type_idx);
int GetAbility(enum monster_id monster_id, int ability_idx);
int GetRecruitRate2(enum monster_id monster_id);
int GetRecruitRate1(enum monster_id monster_id);
int GetExp(enum monster_id monster_id, int level);
void GetEvoParameters(undefined* evo_params, enum monster_id monster_id);
void GetTreasureBoxChances(enum monster_id monster_id, undefined* chances);
int GetIqGroup(enum monster_id monster_id);
int GetSpawnThreshold(enum monster_id monster_id);
bool NeedsItemToSpawn(enum monster_id monster_id);
int GetExclusiveItem(enum monster_id monster_id, int excl_idx);
int GetFamilyIndex(enum monster_id monster_id);
void LoadM2nAndN2m(void);
bool IsNotNickname(char* string, enum monster_id monster_id);
void GetLvlStats(undefined* level_stats, enum monster_id monster_id, int level);
int GetEvoFamily(undefined* monster, undefined* evo_family);
int GetEvolutions(enum monster_id monster_id, enum monster_id* output_list,
                  bool skip_sprite_size_check, bool skip_shedinja_check);
void ShuffleHiddenPower(undefined* dmons_addr);
enum monster_id GetBaseForm(enum monster_id);
enum monster_id GetBaseFormBurmyWormadamShellosGastrodonCherrim(enum monster_id monster_id);
enum monster_id GetBaseFormCastformCherrimDeoxys(enum monster_id monster_id);
int GetAllBaseForms(enum monster_id monster_id);
int GetDexNumberVeneer(enum monster_id monster_id);
enum monster_id GetMonsterIdFromSpawnEntry(struct monster_spawn_entry*);
enum monster_gender GetMonsterGenderVeneer(enum monster_id monster_id);
void SetMonsterId(struct monster_spawn_entry* monster_spawn, enum monster_id monster_id);
void SetMonsterLevelAndId(struct monster_spawn_entry* monster_spawn, int level,
                          enum monster_id monster_id);
uint8_t GetMonsterLevelFromSpawnEntry(struct monster_spawn_entry* entry);
bool IsMonsterValid(enum monster_id monster_id);
bool IsUnown(enum monster_id monster_id);
bool IsShaymin(enum monster_id monster_id);
bool IsCastform(enum monster_id monster_id);
bool IsCherrim(enum monster_id monster_id);
bool IsDeoxys(enum monster_id monster_id);
enum monster_id GetSecondFormIfValid(enum monster_id monster_id);
enum monster_id FemaleToMaleForm(enum monster_id monster_id);
enum monster_id GetBaseFormCastformDeoxysCherrim(enum monster_id monster_id);
bool BaseFormsEqual(enum monster_id monster1, enum monster_id monster2);
bool DexNumbersEqual(enum monster_id monster1, enum monster_id monster2);
bool GendersEqual(enum monster_id monster1, enum monster_id monster2);
bool GendersEqualNotGenderless(enum monster_id monster1, enum monster_id monster2);
bool IsMonsterOnTeam(enum monster_id monster_id, int recruit_strategy);
void GetNbRecruited(undefined* recruit);
undefined4 GetMember(int member_idx);
int GetHeroStrIdIfExists(void);
int GetPartnerStrIdIfExists(void);
int GetFirstTeamMemberStrIdIfExists(void);
int GetSecondTeamMemberStrIdIfExists(void);
int GetThirdTeamMemberStrIdIfExists(void);
struct ground_monster* GetHeroData(void);
struct ground_monster* GetPartnerData(void);
struct ground_monster* GetFirstTeamMemberData(void);
struct ground_monster* GetSecondTeamMemberData(void);
struct ground_monster* GetThirdTeamMemberData(void);
int GetFirstEmptyRecruitSlot(int param_1);
bool CheckTeamMemberField8(undefined2 param_1);
bool IsMonsterIdInNormalRange(enum monster_id monster_id);
struct team_member* GetTeamMemberData(uint8_t index);
undefined* GetTeamMember(int team_id);
void SetTeamSetupHeroAndPartnerOnly(void);
void SetTeamSetupHeroOnly(void);
int GetPartyMembers(uint16_t* party_members);
void RefillTeam(void);
int ClearItem(int team_id, bool check);
void ChangeGiratinaFormIfSkyDungeon(enum dungeon_id dungeon_id);
bool CanLearnIqSkill(int iq_amount, enum iq_skill_id iq_id);
int GetLearnableIqSkills(struct iq_skill_id_8* out_iq_skill_id, enum monster_id monster_id,
                         int monster_iq);
void DisableIqSkill(uint32_t* iq_skills_flags, enum iq_skill_id iq_id);
void EnableIqSkill(uint32_t* iq_skills_flags, enum iq_skill_id iq_id);
enum iq_skill_id GetSpeciesIqSkill(enum monster_id monster_id, int index);
bool IqSkillFlagTest(uint32_t* iq_skill_flags, enum iq_skill_id iq_id);
enum iq_skill_id GetNextIqSkill(enum monster_id monster_id, int monster_iq);
struct ground_monster* GetExplorerMazeMonster(uint8_t entry_number);
undefined4 WriteMonsterInfoToSave(void* start_addr, uint32_t total_len);
undefined4 ReadMonsterInfoFromSave(void* start_addr, uint32_t total_len);
void WriteMonsterToSave(undefined* write_info, struct ground_monster* monster);
void ReadMonsterFromSave(undefined* read_info, struct ground_monster* monster);
void GetEvolutionPossibilities(struct ground_monster* monster, undefined* evo);
int GetMonsterEvoStatus(struct ground_monster* monster);
int GetSosMailCount(int param_1, bool param_2);
bool IsMissionValid(struct mission* mission);
enum mission_generation_result GenerateMission(undefined* param_1, struct mission* mission_data);
void GenerateDailyMissions(void);
int DungeonRequestsDone(uint8_t param_1, bool param_2);
int DungeonRequestsDoneWrapper(uint8_t param_1);
bool AnyDungeonRequestsDone(uint8_t param_1);
int GetAcceptedMission(int mission_id);
int GetMissionByTypeAndDungeon(int start_index, enum mission_type mission_type,
                               undefined* subtype_struct, enum dungeon_id dungeon_id);
bool CheckAcceptedMissionByTypeAndDungeon(enum mission_type mission_type, undefined* subtype_struct,
                                          enum dungeon_id dungeon_id);
int GenerateAllPossibleMonstersList(void);
void DeleteAllPossibleMonstersList(void);
int GenerateAllPossibleDungeonsList(void);
void DeleteAllPossibleDungeonsList(void);
int GenerateAllPossibleDeliverList(void);
void DeleteAllPossibleDeliverList(void);
void ClearMissionData(struct mission* mission);
bool IsMonsterMissionAllowed(enum monster_id monster_id);
bool CanMonsterBeUsedForMissionWrapper(enum monster_id monster_id);
bool CanMonsterBeUsedForMission(enum monster_id monster_id, bool check_story_banned);
bool IsMonsterMissionAllowedStory(enum monster_id monster_id);
bool CanSendItem(enum item_id item_id, bool to_sky);
bool IsAvailableItem(enum item_id item_id);
int GetAvailableItemDeliveryList(undefined* item_buffer);
int GetActorMatchingStorageId(int actor_id);
void ScriptSpecialProcess0x3D(void);
void ScriptSpecialProcess0x3E(void);
void ScriptSpecialProcess0x17(void);
void ItemAtTableIdx(int idx, struct bulk_item* item);
int DungeonSwapIdToIdx(enum dungeon_id dungeon_id);
enum dungeon_id DungeonSwapIdxToId(int idx);
int ResumeBgm(undefined4 param_1, undefined4 param_2, undefined4 param_3);
int FlushChannels(undefined* param_1, int param_2, int param_3);
void UpdateChannels(void);
void WaitForInterrupt(void);
void FileInit(struct file_stream* file);
int Abs(int x);
int Mbtowc(wchar_t* pwc, const char* s, uint32_t n);
bool TryAssignByte(uint8_t* ptr, uint8_t val);
bool TryAssignByteWrapper(uint8_t* ptr, uint8_t val);
uint32_t Wcstombs(char* dest, wchar_t* src, uint32_t n);
void Memcpy(void* dest, void* src, uint32_t n);
void Memmove(void* dest, void* src, uint32_t n);
void* Memset(void* s, int c, uint32_t n);
void* Memchr(void* s, char c, uint32_t n);
int Memcmp(void* s1, void* s2, uint32_t n);
void MemsetInternal(void* s, int c, uint32_t n);
int VsprintfInternalSlice(slice_append_fn_t append, struct slice* str, const char* format,
                          va_list ap);
bool TryAppendToSlice(struct slice* slice, void* data, uint32_t data_len);
int VsprintfInternal(char* str, uint32_t maxlen, const char* format, va_list ap);
int Vsprintf(char* str, const char* format, va_list ap);
int Snprintf(char* str, uint32_t n, const char* format, ...);
int Sprintf(char* str, const char* format, ...);
uint32_t Strlen(const char* s);
void Strcpy(char* dest, const char* src);
void Strncpy(char* dest, const char* src, uint32_t n);
void Strcat(char* dest, const char* src);
void Strncat(char* dest, const char* src, uint32_t n);
int Strcmp(const char* s1, const char* s2);
int Strncmp(const char* s1, const char* s2, uint32_t n);
char* Strchr(const char* string, char c);
uint32_t Strcspn(const char* string, const char* stopset);
char* Strstr(const char* haystack, const char* needle);
uint32_t Wcslen(wchar_t* ws);
float AddFloat(float a, float b);
float DivideFloat(float dividend, float divisor);
double FloatToDouble(float f);
int FloatToInt(float f);
float IntToFloat(int i);
float UIntToFloat(uint32_t u);
float MultiplyFloat(float a, float b);
float Sqrtf(float x);
float SubtractFloat(float a, float b);
unsigned long long DivideInt(int dividend, int divisor);
unsigned long long DivideUInt(uint32_t dividend, uint32_t divisor);
unsigned long long DivideUIntNoZeroCheck(uint32_t dividend, uint32_t divisor);

#endif
