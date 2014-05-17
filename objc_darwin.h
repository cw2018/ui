/* 28 february 2014 */

/* apparently this header is included by other headers generated by cgo, wrecking the structures below, so wheee include guards */
/* the change that introduced this was [master 9b4e30c] ("Started to build a single global delegate object; now to fix issues.") */
#ifndef __GO_UI_OBJC_DARWIN_H__
#define __GO_UI_OBJC_DARWIN_H__

/* the Objective-C runtime headers, for id */
#include <objc/message.h>
#include <objc/objc.h>
#include <objc/runtime.h>

#include <stdint.h>

/* wrapper types since the meaning of NSRect, NSSize, and NSPoint are CPU architectured-dependent; also because they're in an Objective-C-only header */
struct xrect {
	intptr_t x;
	intptr_t y;
	intptr_t width;
	intptr_t height;
};

struct xsize {
	intptr_t width;
	intptr_t height;
};

struct xpoint {
	intptr_t x;
	intptr_t y;
};

/* objc_darwin.m */
extern id toNSString(char *);
extern char *fromNSString(id);
extern void display(id);
extern struct xrect frame(id);
extern id makeScrollView(id);
extern void giveScrollViewBezelBorder(id);
extern id scrollViewContent(id);

/* area_darwin.m */
extern id makeArea(void);
extern void drawImage(void *, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t);
extern uintptr_t modifierFlags(id);
extern struct xpoint getTranslatedEventPoint(id, id);
extern intptr_t buttonNumber(id);
extern intptr_t clickCount(id);
extern uintptr_t pressedMouseButtons(void);
extern uintptr_t keyCode(id);

/* delegateuitask_darwin.m */
extern id makeAppDelegate(void);
extern id windowGetContentView(id);
extern BOOL initCocoa(id);
extern void douitask(id, void *);
extern void breakMainLoop(void);
extern void cocoaMainLoop(void);

/* dialog_darwin.m */
extern void msgBox(id, id);
extern void msgBoxError(id, id);

/* listbox_darwin.m */
extern id toListboxItem(id, id);
extern id fromListboxItem(id, id);
extern id makeListboxArray(void);
extern void listboxArrayAppend(id, id);
extern void listboxArrayInsertBefore(id, id, uintptr_t);
extern void listboxArrayDelete(id, uintptr_t);
extern id listboxArrayItemAt(id, uintptr_t);
extern void bindListboxArray(id, id, id, id);
extern id boundListboxArray(id, id);
extern id makeListboxTableColumn(id);
extern id listboxTableColumn(id, id);
extern id makeListbox(id, BOOL);
extern id listboxSelectedRowIndexes(id);
extern uintptr_t listboxIndexesCount(id);
extern uintptr_t listboxIndexesFirst(id);
extern uintptr_t listboxIndexesNext(id, uintptr_t);
extern intptr_t listboxLen(id);
extern void listboxDeselectAll(id);

/* prefsize_darwin.m */
extern struct xsize controlPrefSize(id);
extern struct xsize listboxPrefSize(id);
extern struct xsize pbarPrefSize(id);

/* sysdata_darwin.m */
extern void addControl(id, id);
extern void controlShow(id);
extern void controlHide(id);
extern void applyStandardControlFont(id);
extern id makeWindow(id);
extern void windowShow(id);
extern void windowHide(id);
extern void windowSetTitle(id, id);
extern id windowTitle(id);
extern id makeButton(void);
extern void buttonSetTargetAction(id, id);
extern void buttonSetText(id, id);
extern id buttonText(id);
extern id makeCheckbox(void);
extern id makeCombobox(BOOL);
extern id comboboxText(id, BOOL);
extern void comboboxAppend(id, BOOL, id);
extern void comboboxInsertBefore(id, BOOL, id, intptr_t);
extern intptr_t comboboxSelectedIndex(id);
extern void comboboxDelete(id, intptr_t);
extern intptr_t comboboxLen(id);
extern void comboboxSelectIndex(id, BOOL, intptr_t);
extern id makeLineEdit(BOOL);
extern void lineeditSetText(id, id);
extern id lineeditText(id);
extern id makeLabel(void);
extern id makeProgressBar(void);
extern void setRect(id, intptr_t, intptr_t, intptr_t, intptr_t);
extern BOOL isCheckboxChecked(id);
extern void windowSetContentSize(id, intptr_t, intptr_t);
extern void setProgress(id, intptr_t);
extern void setAreaSize(id, intptr_t, intptr_t);

#endif
